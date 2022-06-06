#include <Geode.hpp>
#include <Cocoa/Cocoa.h>
#include "BypassCallback.h"

USE_GEODE_NAMESPACE();

// don't wanna RE, so i'm just gonna make a stub for the thing i want
struct CCDirectorCaller_ {
    char a[0x10];
    NSTimer* renderTimer;
};

// hook ccdirectorcaller to use our timers
void CCDirectorCaller_setAnimationInterval(CCDirectorCaller_* caller, void*, double) {
    [caller->renderTimer invalidate];
    caller->renderTimer = nil;
    caller->renderTimer = [NSTimer timerWithTimeInterval:1.0/GLOBAL_FPS
                                          target:[BypassCallback sharedCallback]
                                        selector:@selector(physicsFired:)
                                        userInfo:nil
                                         repeats:YES];
    
    [[NSRunLoop currentRunLoop] addTimer:caller->renderTimer 
                                 forMode:NSDefaultRunLoopMode];
    [[NSRunLoop currentRunLoop] addTimer:caller->renderTimer 
                                 forMode:NSEventTrackingRunLoopMode];
}

GEODE_API bool GEODE_DLL geode_load(Mod* m) {
    m->addHook<&CCDirectorCaller_setAnimationInterval, geode::core::meta::DefaultConv>("Balls and Cock", (void*)(geode::base::get() + 0x1da750));

    dispatch_async(dispatch_get_main_queue(), ^{
        AppDelegate::get()->setAnimationInterval(GLOBAL_FPS);

        NSTimer* renderTimer = [NSTimer timerWithTimeInterval:1.0/60.0
                                                       target:[BypassCallback sharedCallback]
                                                     selector:@selector(renderFired:)
                                                     userInfo:nil
                                                      repeats:YES];

        [[NSRunLoop currentRunLoop] addTimer:renderTimer forMode:NSDefaultRunLoopMode];
        [[NSRunLoop currentRunLoop] addTimer:renderTimer forMode:NSEventTrackingRunLoopMode];

    });
    return true;
}
