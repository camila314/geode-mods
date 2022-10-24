#include <Geode/modify/PlayLayer.hpp>

USE_GEODE_NAMESPACE();

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

	void destroyPlayer(PlayerObject*, GameObject*) {}
	void onQuit() {
		if (s_paused) {
			PlayLayer::onQuit();
		}
	}

	void pauseGame(bool b) {
		PlayLayer::pauseGame(b);

		s_paused = true;
	}
};
