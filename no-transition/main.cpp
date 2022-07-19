#include <Geode.hpp>
using namespace cocos2d;

class $(CCTransitionFade) {
	CCTransitionFade* create(float, CCScene* c) {
		return CCTransitionFade::create(0.1, c);
	}
};
