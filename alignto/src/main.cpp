#include <Geode/Geode.hpp>
#include <Geode/Modify.hpp>
#include <Geode/Utils.hpp>
#include <UIBuilder.hpp>

using namespace geode::prelude;
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
		Build<CCLabelBMFont>::create("Drag to create an alignment axis", "bigFont.fnt")
			.center()
			.move(0, 130)
			.scale(0.5)
			.parent(this);

		m_lineDrawer = Build<CCDrawNode>::create().parent(this);

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
	bool init(LevelEditorLayer* lel) {
		EditorPauseLayer::init(lel);

		auto btn = Build<ButtonSprite>::create("Align To", 30, 0, 0.4, true, "bigFont.fnt", "GJ_button_04.png", 30.0)
			.intoMenuItem([=](auto) {
				auto objs = EditorUI::get()->m_selectedObjects;

				if (objs->count() > 0) {
					this->onExit();
					this->removeMeAndCleanup();

					LevelEditorLayer::get()->addChild(AlignToLayer::create(), 9999999);
				}
			}).collect();

		auto ch = getChildByID("small-actions-menu");
		ch->insertBefore(btn, ch->getChildByID("align-x-button"));
		ch->updateLayout();

		return true;
	}
};