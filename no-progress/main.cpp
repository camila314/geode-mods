#include <Geode/modify/PlayLayer.hpp>

class $modify(PlayLayer) {
    void update(float dt) {
        PlayLayer::update(dt);
        m_sliderGrooveSprite->setVisible(false);
        m_percentLabel->setPositionX(cocos2d::CCDirector::sharedDirector()->getWinSize().width / 2 - (m_percentLabel->getContentSize().width / 2));
    }
};

