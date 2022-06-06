#include <Geode.hpp>
#include <Cocoa/Cocoa.h>

inline double GLOBAL_FPS = 60.0;

@interface BypassCallback : NSObject
    + (BypassCallback*)sharedCallback;
    - (void)renderFired: (id)ok;
    - (void)physicsFired:(id)ok;
@end
