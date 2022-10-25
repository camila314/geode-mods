#include <Geode/Geode.hpp>

USE_GEODE_NAMESPACE();

void fps_shower_init();
void object_limit_init();

GEODE_API bool GEODE_CALL geode_load(Mod* mod) {
	fps_shower_init();
	object_limit_init();
    return true;
}