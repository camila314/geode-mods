#include <Geode/modify/GameObject.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/Bindings.hpp>
#include "DebugWrapper.hpp"

USE_GEODE_NAMESPACE();
using namespace cocos2d;

cocos2d::CCNode* getChildByFnRecursive(cocos2d::CCNode* node, std::function<bool(cocos2d::CCNode*)> fn) {
    if (fn(node)) return node;

    auto children = node->getChildren();
    if (!children) return nullptr;

    for (int i = 0; i < children->count(); ++i) {
        auto child = getChildByFnRecursive((cocos2d::CCNode*)children->objectAtIndex(i), fn);
        if(child)
            return child;
    }

    return nullptr;
}

bool g_layoutMode = false;

class $(MyGameObject, GameObject) {
	bool m_realVisible;
	cocos2d::_ccColor3B m_realColor;

	void setVisible(bool v) {
		if (g_layoutMode) {
			m_fields->m_realVisible = v;

			if (m_objectType == GameObjectType::Decoration) {
				GameObject::setVisible(false);
			} else {
				GameObject::setVisible(v); // for CCParticleSystem (idk why)
				GameObject::setVisible(true);
			}
		} else GameObject::setVisible(v);
	}

	void revertVisibility() {
		setVisible(m_fields->m_realVisible);
	}

	void setOpacity(unsigned char g) {
		GameObject::setOpacity(g);

		if (g_layoutMode && m_objectType != GameObjectType::Decoration) {
			CCSpritePlus::setOpacity(255);
			if (m_glowSprite)
				m_glowSprite->setOpacity(255);
		}
	}

	void setGlowColor(cocos2d::_ccColor3B const& col) {
		if (g_layoutMode) {
			GameObject::setGlowColor(ccc3(255, 255, 255));
		} else {
			GameObject::setGlowColor(col);
		}
	}
};

/*class $(GJEffectManager) {
	bool shouldBlend(int id) {
		return g_layoutMode ? false : GJEffectManager::shouldBlend(id);
	}
};*/

class $(MyPauseLayer, PauseLayer) {
	static PauseLayer* create(bool b) {
		auto pl = PauseLayer::create(b);

		auto ws = CCDirector::sharedDirector()->getWinSize();
		auto pos = ((ws.width / 2) + 50) - 300;

		auto menu = CCMenu::create();

		pl->createToggleButton("Layout Mode", menu_selector(MyPauseLayer::onToggleDeco), !g_layoutMode, menu, ccp(pos, 42));
		pl->addChild(menu);

		return pl;
	}

	void onToggleDeco(cocos2d::CCObject*) {
		g_layoutMode = !g_layoutMode;

		CCArrayExt<MyGameObject> objects(PlayLayer::get()->m_objects);

		for (auto ob : objects) {
			ob->setOpacity(ob->getOpacity());
			ob->setVisible(ob->isVisible());
			ob->updateSecondaryColor();

			if (!g_layoutMode)
				ob->revertVisibility();
		}
	}
};
