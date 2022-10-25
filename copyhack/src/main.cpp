#include <Geode/modify/LevelInfoLayer.hpp>
USE_GEODE_NAMESPACE();

class $(LevelInfoLayer) {
	static LevelInfoLayer* create(GJGameLevel* g) {
		g->m_passwordRand = 21;
		g->m_passwordSeed = 20;
		return LevelInfoLayer::create(g);
	}
};