#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include "DebugWrapper.hpp"

USE_GEODE_NAMESPACE();

using namespace cocos2d;

CCTextInputNode* g_tin;
float g_speedMult = 1.0;

class $modify(MyPauseLayer, PauseLayer) {
	static PauseLayer* create(bool b) {
		auto pl = PauseLayer::create(b);

		auto width = 50.0;
		auto height = 30.0;

		float clampMult = fmin(1, height/40.0);

		g_tin = CCTextInputNode::create(width, height, "Speed", "bigFont.fnt");
		g_tin->setLabelPlaceholderColor(ccc3(120, 170, 240));
		g_tin->setMaxLabelScale(height/50.0);
		g_tin->setAllowedChars("1234567890.");

		auto box = cocos2d::extension::CCScale9Sprite::create("square02b_small.png");
		box->setOpacity(100);
		box->setColor(ccc3(0,0,0));
		box->setContentSize(CCSizeMake((width+10)/clampMult, fmax(height-10,40)));
		box->setScale(clampMult);

		auto btn = ButtonSprite::create("Speed");
		auto mitem = CCMenuItemSpriteExtra::create(btn, pl, menu_selector(MyPauseLayer::onSpeed));

		auto pos = CCPoint(CCDirector::sharedDirector()->getWinSize() / 2.0) + ccp(-225, 0);

		box->setPosition(pos);
		g_tin->setPosition(pos);
		mitem->setPosition(ccp(-225, 50));

		pl->addChild(g_tin);
		pl->addChild(box);

		auto menu = CCMenu::create();
		menu->addChild(mitem);
		pl->addChild(menu);

		return pl;
	}

	void onSpeed(CCObject* ob) {
		auto f = atof(g_tin->getString());
		if (f > 0.01)
			g_speedMult = f;
	}
};

class $(PlayLayer) {
	void update(float dt) {
		PlayLayer::update(dt * g_speedMult);
	}
};
