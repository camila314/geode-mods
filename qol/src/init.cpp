#include <Geode.hpp>

USE_GEODE_NAMESPACE();

void fps_shower_init();

GEODE_API bool GEODE_CALL geode_load(Mod* mod) {
	Interface::get()->init(mod);
	fps_shower_init();
    return true;
}