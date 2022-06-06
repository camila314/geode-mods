/**
 * Include the Geode headers.
 */
#include <Geode.hpp>

class $(PlayLayer) {
	void update(float dt) {
		m_antiCheatPassed = true;
		PlayLayer::update(dt);
		m_antiCheatPassed = true;
	}

	void vfDChk() {}
};