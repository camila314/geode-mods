#include <Geode.hpp>

using namespace cocos2d;

extern double GLOBAL_FPS;

// ac bypass
class $(PlayLayer) {
    void update(float dt) {
        auto lt = m_level->m_levelType;
        m_level->m_levelType = GJLevelType::Local;
        PlayLayer::update(dt);
        m_level->m_levelType = lt;
    }
};

// the UI
class $(fpsThing, MoreVideoOptionsLayer) {
    field<CCTextInputNode*> fps;

    bool init() {
        MoreVideoOptionsLayer::init();

        auto winSize = CCDirector::sharedDirector()->getWinSize();
        auto menu = m_buttonMenu;

        auto btn = ButtonSprite::create("Set FPS", 50, 0, 0.7, 0, "bigFont.fnt", "GJ_button_01.png", 30);
        auto mitem = CCMenuItemSpriteExtra::create(btn, btn, this, menu_selector(fpsThing::onSet));
        mitem->setPosition(ccp(0, -50));

        auto input = CCTextInputNode::create(50, 50, "FPS", 12, "bigFont.fnt");
        input->setPosition(ccp(0, 0));
        input->setLabelPlaceholderColor(ccc3(120, 170, 240));

        auto box = extension::CCScale9Sprite::create("square02b_small.png");
        box->setOpacity(100);
        box->setColor(ccc3(0,0,0));
        box->setContentSize(CCSizeMake(60, 30));

        m_buttonMenu->addChild(mitem);
        m_buttonMenu->addChild(box);
        m_buttonMenu->addChild(input);

        this->*fps = input;

        return true;
    } 
    void onSet(cocos2d::CCObject* m) {
        auto input = this->*fps;
        int fpsVal = atoi(input->getString());
        if (fpsVal < 1)
            return;

        GLOBAL_FPS = fpsVal;
        AppDelegate::get()->setAnimationInterval(GLOBAL_FPS);
    }

    void onClose(cocos2d::CCObject* m) {
        auto input = this->*fps;
        input->onClickTrackNode(false);

        MoreVideoOptionsLayer::onClose(m);
    }
};
