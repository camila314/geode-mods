#include "BypassCallback.h"

using namespace cocos2d;

// the original drawScene calls CCScheduler::update, but we do that in another timer.
class CustomDirector : public cocos2d::CCDirector {
 public:
    void drawScene2() {
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

    int getFrames() {
        return m_uTotalFrames;
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

    // update CCScheduler and dispatch events
    - (void)physicsFired:(id)ok {
        double currentTime = [[NSDate date] timeIntervalSince1970];
        double dt;

        if (lastFrameTime < 0.00001)
            dt = 1.0/GLOBAL_FPS;
        else
            dt = currentTime - lastFrameTime;

        lastFrameTime = currentTime;

        CCDirector::sharedDirector()->getScheduler()->update(dt);
        [(id)[NSClassFromString(@"CCEventDispatcher") sharedDispatcher] dispatchQueuedEvents];
    }

    - (void)renderFired:(id)ok {
            NSOpenGLView* openGLView = NSApp.mainWindow.contentView;
            NSOpenGLContext* glContext = openGLView.openGLContext;

            [glContext makeCurrentContext];
            CGLLockContext(glContext.CGLContextObj);
            
            ((CustomDirector*)cocos2d::CCDirector::sharedDirector())->drawScene2();

            [glContext flushBuffer];
            CGLUnlockContext(glContext.CGLContextObj);
    }
@end
