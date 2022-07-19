#include <Geode.hpp>
USE_GEODE_NAMESPACE();

class $(LevelInfoLayer) {
	static LevelInfoLayer* create(GJGameLevel* g) {
		g->m_password_rand = 21;
		g->m_password_seed = 20;
		return LevelInfoLayer::create(g);
	}
};