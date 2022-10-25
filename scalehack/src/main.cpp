/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>

USE_GEODE_NAMESPACE();

class Patch2 : public Patch {
 public:
 	Patch2(byte_array patch, byte_array original, uintptr_t address) : Patch() {
 		m_patch = patch;
 		m_original = original;
 		m_address = (void*)address;
 		m_owner = Mod::get();
 	}
};

GEODE_API void GEODE_DLL geode_load(Mod* m) {
	Patch2* lol = new Patch2({'\xeb'}, {'\x76'}, base::get() + 0x18D811);
	lol->apply();
	Patch2* lol2 = new Patch2({'\xeb'}, {'\x76'}, base::get() + 0x18D7D9);
	lol2->apply();


	Patch2* lol3 = new Patch2({'\x90', '\x90', '\x90', '\x90', '\x90', '\x90'}, {'\x90', '\x90', '\x90', '\x90', '\x90', '\x90'}, base::get() + 0x25332);
	lol3->apply();
	Patch2* lol4 = new Patch2({'\x90', '\x90', '\x90', '\x90', '\x90', '\x90'}, {'\x90', '\x90', '\x90', '\x90', '\x90', '\x90'}, base::get() + 0x2533f);
	lol4->apply();
}
