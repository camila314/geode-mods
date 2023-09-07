#include <Geode/Geode.hpp>
#include <Geode/Modify/PlayLayer.hpp>
#include <Geode/Modify/UILayer.hpp>
#include <Geode/Modify/PauseLayer.hpp>
#include <vector>

using namespace geode::prelude;
using namespace cocos2d;

std::vector<std::pair<StartPosObject*, CCPoint>> g_startPoses;
int g_startPosIndex;
CCLabelBMFont* g_startPosText;
bool g_toReset;


class $(MyPlayLayer, PlayLayer) {
	void vfDChk() {}

	void updateIndex(bool increment) {

		if (g_startPoses.empty() || m_isPracticeMode)
			return;

		if (increment) {
			g_startPosIndex++;
		} else {
			g_startPosIndex--;
		}

		if (g_startPosIndex == g_startPoses.size()) {
			g_startPosIndex = -1;
		} else if (g_startPosIndex < -1) {
			g_startPosIndex = g_startPoses.size() - 1;
		}

		auto colorPulseBegin = CCTintTo::create(0.0, 0, 255, 0);
		auto colorPulseEnd = CCTintTo::create(0.5, 255, 255, 255);

		auto opacityPulseBegin = CCFadeTo::create(0.0, 255);
		auto opacityPulseEnd = CCFadeTo::create(0.5, 50);

		auto label = std::string("StartPos ") + std::to_string(g_startPosIndex + 1) + "/" + std::to_string(g_startPoses.size());
		g_startPosText->setString(label.c_str());
		g_startPosText->runAction(CCSequence::create(colorPulseBegin, colorPulseEnd, nullptr));
		g_startPosText->runAction(CCSequence::create(opacityPulseBegin, opacityPulseEnd, nullptr));

		m_startPosCheckpoint = nullptr;
		if (g_startPosIndex == -1) {
			m_startPos = nullptr;
			m_playerStartPosition = ccp(0, 105);
		} else {
			m_startPos = g_startPoses[g_startPosIndex].first;
			m_playerStartPosition = g_startPoses[g_startPosIndex].second;
		}

		resetLevel();
		if (m_isPaused)
			GameSoundManager::sharedManager()->stopBackgroundMusic();
	}

	void resetLevel() {
		if (m_startPos == nullptr) {
			m_isTestMode = false;
		} else {
			m_isTestMode = true;
		}

		PlayLayer::resetLevel();
	}

	bool init(GJGameLevel* gl) {
		g_startPosText = CCLabelBMFont::create("StartPos 0/0", "bigFont.fnt");
		g_startPosIndex = -1;
		g_startPoses = {};

		PlayLayer::init(gl);

		auto corner = CCDirector::sharedDirector()->getScreenTop();
		g_startPosText->setPosition(5 , corner - 25);
		g_startPosText->setScale(0.4);
		g_startPosText->setAnchorPoint({0, 0.5});
		g_startPosText->setOpacity(50);

		if (g_startPoses.empty()) 
			g_startPosText->setVisible(false);
		addChild(g_startPosText, 1000);

		return true;
	}

	void addObject(GameObject* g) {
		PlayLayer::addObject(g);
		if (g->m_objectID == 31) {
			g->retain();
			g_startPoses.push_back({reinterpret_cast<StartPosObject*>(g), g->getPosition()});
			g_startPosIndex += 1;
			auto label = std::string("StartPos ") + std::to_string(g_startPosIndex + 1) + "/" + std::to_string(g_startPoses.size());
			g_startPosText->setString(label.c_str());
		}
	}	
};

class $(UILayer) {
	void keyDown(cocos2d::enumKeyCodes kc) {
		auto mpl = reinterpret_cast<MyPlayLayer*>(PlayLayer::get());

		if (kc == KEY_Left || kc == KEY_Right) {
			mpl->updateIndex(kc == KEY_Right);
		} else {
			UILayer::keyDown(kc);
		}
	}
};

class $(PauseLayer) {
	void keyDown(cocos2d::enumKeyCodes kc) {
		auto mpl = reinterpret_cast<MyPlayLayer*>(PlayLayer::get());

		if (kc == KEY_Left || kc == KEY_Right) {
			mpl->updateIndex(kc == KEY_Right);
		} else {
			PauseLayer::keyDown(kc);
		}
	}
};
