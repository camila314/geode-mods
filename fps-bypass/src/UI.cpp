#include <Geode.hpp>

using namespace cocos2d;

extern double GLOBAL_FPS;
extern void updateFPS();

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
        auto mitem = CCMenuItemSpriteExtra::create(btn, btn, this, menu_selector(fpsThing::onClose));
        mitem->setPosition(ccp(0, -50));

        auto input = CCTextInputNode::create(50, 50, "FPS", 12, "bigFont.fnt");
        input->setPosition(ccp(0, 0));
        input->setLabelPlaceholderColor(ccc3(120, 170, 240));
        input->setString(std::to_string((int)GLOBAL_FPS).c_str());

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

    void onClose(cocos2d::CCObject* m) {
        auto input = this->*fps;
        input->onClickTrackNode(false);
        MoreVideoOptionsLayer::onClose(m);

        int fpsVal = atof(input->getString());
        if (fpsVal < 1)
            return;
        if (fpsVal != GLOBAL_FPS) {
            GLOBAL_FPS = fpsVal;
            CCApplication::sharedApplication()->setAnimationInterval(fpsVal);
        }
    }
};
