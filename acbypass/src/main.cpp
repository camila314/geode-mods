#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $(PlayLayer) {
	void update(float dt) {
		m_antiCheatPassed = true;
		PlayLayer::update(dt);
	}
};
