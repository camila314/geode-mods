#include <Geode/modify/CCDirector.hpp>
#include "BypassCallback.h"

using namespace cocos2d;

class $(CCDirector) {
 public:
    void drawScene() {
        // Limit CCScheduler::update() since we do that in the physics timer
        // GLOBAL_ENABLED so the initialzing doesn't cause a softlock
        if (!m_bPaused & !GLOBAL_ENABLED) {
            m_pScheduler->update(m_fDeltaTime);
        }
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if (m_pNextScene) {
            setNextScene();
        }

        glPushMatrix();

        if (m_pRunningScene) {
            m_pRunningScene->visit();
        }

        if (m_pNotificationNode) {
            m_pNotificationNode->visit();
        }
        
        glPopMatrix();

        m_uTotalFrames++;

        if (m_pobOpenGLView) {
            m_pobOpenGLView->swapBuffers();
        }
    }
};

@implementation BypassCallback {
    double lastFrameTime;
}
    + (BypassCallback*)sharedCallback {
        static BypassCallback* shared;
        if (!shared) {
            shared = [[BypassCallback alloc] init];
        }

        return shared;
    }

    // Run CCScheduler::update(). We must keep track of our own frametimes
    - (void)physicsFired:(id)ok {
        double currentTime = [[NSDate date] timeIntervalSince1970];
        double dt;

        if (lastFrameTime < 0.00001)
            dt = 1.0/GLOBAL_FPS;
        else
            dt = currentTime - lastFrameTime;

        lastFrameTime = currentTime;

        CCDirector::sharedDirector()->getScheduler()->update(dt);
    }
@end
