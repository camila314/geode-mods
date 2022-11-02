#include <Geode/modify/PlayLayer.hpp>

USE_GEODE_NAMESPACE();

class $(PlayLayer) {
	void update(float dt) {
		m_antiCheatPassed = true;
		PlayLayer::update(dt);
	}
};
