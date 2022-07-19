/**
 * Include the Geode headers.
 */
#include <Geode.hpp>

/**
 * Brings cocos2d and all Geode namespaces 
 * to the current scope.
 */
USE_GEODE_NAMESPACE();

class Patch2 : public Patch {
 public:
 	Patch2(byte_array patch, byte_array original, uintptr_t address) : Patch() {
 		m_patch = patch;
 		m_original = original;
 		m_address = (void*)(base::get() + address);
 		m_owner = Mod::get();
 	}

 	Patch2(char patch, char original, uintptr_t address) : Patch() {
 		m_patch = {patch};
 		m_original = {original};
 		m_address = (void*)(base::get() + address);
 		m_owner = Mod::get();
 	}
};

GEODE_API void GEODE_DLL geode_load(Mod* m) {
	(new Patch2('\xeb', '\x7c', 0x18bfa))->apply();
	(new Patch2('\xeb', '\x7c', 0x18f25))->apply();
	(new Patch2('\xeb', '\x7c', 0x1b991))->apply();

	(new Patch2({'\x66', '\x0f', '\x1f', '\x44', '\x00', '\x00'}, {'\x66', '\x0f', '\x1f', '\x44', '\x00', '\x00'}, 0x949cd))->apply();
	(new Patch2({'\x66', '\x0f', '\x1f', '\x44', '\x00', '\x00'}, {'\x66', '\x0f', '\x1f', '\x44', '\x00', '\x00'}, 0x94b1d))->apply();
}
