#include <Geode.hpp>

class $(PlayLayer) {

	void startMusic() {
		auto p = m_isPracticeMode;
		m_isPracticeMode = false; // pretend there is no practice mode
		PlayLayer::startMusic();
		m_isPracticeMode = p;
	}

	void togglePracticeMode(bool p) {
		if (!m_isPracticeMode && p) {
			// receate function without the music restart
			m_isPracticeMode = p;
			m_UILayer->toggleCheckpointsMenu(p);
			PlayLayer::startMusic();
			if (p) stopActionByTag(0x12);

		} else {
			PlayLayer::togglePracticeMode(p);
		}
	}
};

class $(PlayerObject) {
	void playDeathEffect() {
		// stop music on death, just like normal gameplay
		GameSoundManager::sharedManager()->stopBackgroundMusic();
		PlayerObject::playDeathEffect();
	}
};
