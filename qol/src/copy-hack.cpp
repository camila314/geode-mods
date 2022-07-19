#include <Geode.hpp>
USE_GEODE_NAMESPACE();

class $(LevelInfoLayer) {
	static LevelInfoLayer* create(GJGameLevel* g) {
		g->m_passwordSeed = 20; // it can be anything
		g->m_passwordRand = g->m_passwordSeed + 1;
		return LevelInfoLayer::create(g);
	}
};
