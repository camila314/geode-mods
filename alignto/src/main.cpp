#include "Geode/cocos/CCDirector.h"
#include "Geode/cocos/label_nodes/CCLabelBMFont.h"
#include "Geode/cocos/layers_scenes_transitions_nodes/CCLayer.h"
#include "ccTypes.h"
#include <Geode/Geode.hpp>
#include <Geode/Modify.hpp>
#include <Geode/Utils.hpp>

USE_GEODE_NAMESPACE();
using namespace geode::cocos;

class AlignToLayer : public CCLayerColor {
 public:
	static AlignToLayer* create() {
		auto pRet = new AlignToLayer();
		
		if (pRet && pRet->CCLayerColor::initWithColor(ccc4(50, 50, 50, 100))) {
			if (pRet->init()) {
				pRet->autorelease();
				return pRet;
			}
		}
		
		CC_SAFE_DELETE(pRet);
		return NULL;
	}

	bool init() override {
		auto label = CCLabelBMFont::create("Drag to create an alignment axis", "bigFont.fnt");
		label->setPosition(CCDirector::sharedDirector()->getWinSize() / 2 + ccp(0, 130));
		label->setScale(0.5);
		addChild(label);

		m_lineDrawer = CCDrawNode::create();
		addChild(m_lineDrawer);

		registerWithTouchDispatcher();
		CCDirector::sharedDirector()->getTouchDispatcher()->incrementForcePrio(2);
		setTouchEnabled(true);
		setTouchMode(cocos2d::kCCTouchesOneByOne);
		return true;
	}

	bool ccTouchBegan(CCTouch* t, CCEvent* e) override {
		m_startPos = t->getLocation();
		return true;
	}

	void ccTouchMoved(CCTouch* t, CCEvent* e) override {
		m_lineDrawer->clear();
		m_lineDrawer->drawSegment(m_startPos, t->getLocation(), 2, ccc4FFromccc3B(ccc3(25, 0, 240)));
	}

	void ccTouchEnded(CCTouch* t, CCEvent* e) override {
		m_lineDrawer->clear();
		auto endPos = t->getLocation();
		auto angleFromVertical = atan2(endPos.x - m_startPos.x, endPos.y - m_startPos.y) * (180 / 3.14159);
		auto eui = EditorUI::get();

		auto center = eui->getGroupCenter(eui->m_selectedObjects, true);

		eui->rotateObjects(eui->m_selectedObjects, -angleFromVertical, center);
		eui->alignObjects(eui->m_selectedObjects, true);
		eui->rotateObjects(eui->m_selectedObjects, angleFromVertical, center);

		this->removeFromParentAndCleanup(true);
	}
 protected:
 	CCPoint m_startPos;
 	CCDrawNode* m_lineDrawer;
};

class $(MyPauseLayer, EditorPauseLayer) {
	void customSetup() {
		EditorPauseLayer::customSetup();

		auto ch = findFirstChildRecursive<ButtonSprite>(this, [](ButtonSprite* btn) {
			return strcmp(btn->m_label->getString(), "AlignX") == 0;
		})->getParent();

		log::info("{}", ch->getParent()->convertToWorldSpace(ch->getPosition()));

		auto sprite = ButtonSprite::create("Align To", 30, 0, 0.4, true, "bigFont.fnt", "GJ_button_04.png", 30.0);

		auto mitem = CCMenuItemSpriteExtra::create(sprite, sprite, this, menu_selector(MyPauseLayer::onAlignTo));
		mitem->addChild(sprite);
		mitem->setPosition(ch->getPosition() + ccp(0, 35));

		ch->getParent()->addChild(mitem);
	}

	void onAlignTo(CCObject*) {
		auto objs = EditorUI::get()->m_selectedObjects;

		if (objs->count() > 0) {
			this->onExit();
			this->removeMeAndCleanup();

			LevelEditorLayer::get()->addChild(AlignToLayer::create(), 9999999);
		}
	}
};