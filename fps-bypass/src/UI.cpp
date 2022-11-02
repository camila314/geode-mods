#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/MoreVideoOptionsLayer.hpp>
#include <Geode/modify/Field.hpp>
#include "global.h"

USE_GEODE_NAMESPACE();

// ac bypass
static bool s_paused = false;
class $(PlayLayer) {
	bool init(GJGameLevel* gl) {
		PlayLayer::init(gl);
		s_paused = false;
		return true;
	}

	void resume() {
		PlayLayer::resume();
		s_paused = false;
	}

	void onQuit() {
        double percent = (m_player1->getPositionX() / m_levelLength) * 100;

		if (s_paused || percent >= 95) {
			PlayLayer::onQuit();
		}
	}

	void pauseGame(bool b) {
		PlayLayer::pauseGame(b);
		s_paused = true;
	}
};


// the UI
class $(fpsThing, MoreVideoOptionsLayer) {
    bool init() {
        MoreVideoOptionsLayer::init();

        auto winSize = CCDirector::sharedDirector()->getWinSize();
        auto menu = m_buttonMenu;

        auto btn = ButtonSprite::create("Set FPS", 50, 0, 0.7, 0, "bigFont.fnt", "GJ_button_01.png", 30);
        auto mitem = CCMenuItemSpriteExtra::create(btn, btn, this, menu_selector(fpsThing::onClose));
        mitem->setPosition(ccp(0, -50));

        auto input = CCTextInputNode::create(50, 50, "FPS", 12, "bigFont.fnt");
        input->setPosition(ccp(0, 0));
        input->setLabelPlaceholderColor(ccc3(120, 170, 240));
        input->setString(std::to_string((int)g_fps).c_str());
        input->setTag(0x3141);

        auto box = extension::CCScale9Sprite::create("square02b_small.png");
        box->setOpacity(100);
        box->setColor(ccc3(0,0,0));
        box->setContentSize(CCSizeMake(60, 30));

        m_buttonMenu->addChild(mitem);
        m_buttonMenu->addChild(box);
        m_buttonMenu->addChild(input);

        return true;
    } 

    void onClose(cocos2d::CCObject* m) {
        auto input = reinterpret_cast<CCTextInputNode*>(m_buttonMenu->getChildByTag(0x3141));

        input->onClickTrackNode(false);
        MoreVideoOptionsLayer::onClose(m);

        int fpsVal = atof(input->getString());
        if (fpsVal < 1)
            return;
        if (fpsVal != g_fps) {
            g_fps = fpsVal;
            updateFPS();
        }
    }
};
