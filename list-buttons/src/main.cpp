#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include <Geode/modify/GameLevelManager.hpp>
#include <UIBuilder.hpp>

using namespace geode::prelude;
using namespace geode::cocos;

class $(LevelSearchLayer) {
	bool init() {
		LevelSearchLayer::init();

		getChildByID("filters-title")->setVisible(false);
		getChildByID("quick-search-title")->setVisible(false);

		auto menu = getChildByID("quick-search-menu");
		auto bg = getChildByID("quick-search-bg");

		bg->setContentSize(bg->getContentSize() + CCSize(0, 35.0));
		menu->setPositionY(menu->getPositionY() - 17.5);

		auto demon_button = Build<CCSprite>::createSpriteName("GJ_longBtn03_001.png")
			.intoMenuItem([=](auto) { openSearch(3141); })
			.pos(menu->getChildByID("most-downloaded-button")->getPosition() + ccp(0, 35))
			.parent(menu)
			.intoNewChild(CCLabelBMFont::create("Demon List", "bigFont.fnt"))
				.scale(0.55)
				.pos(70, 17)
			.intoNewSibling(Build<CCSprite>::createSpriteName("rankIcon_all_001.png"))
				.pos(140, 16)
			.intoParent()
			.collect();
		demon_button->setID("demon-list-button");

		auto challenge_button = Build<CCSprite>::createSpriteName("GJ_longBtn03_001.png")
			.intoMenuItem([=](auto) { openSearch(3142); })
			.pos(menu->getChildByID("most-liked-button")->getPosition() + ccp(0, 35))
			.parent(menu)
			.intoNewChild(CCLabelBMFont::create("Challenge List", "bigFont.fnt"))
				.scale(0.45)
				.pos(70, 17)
			.intoNewSibling(Build<CCSprite>::createSpriteName("rankIcon_top100_001.png"))
				.pos(145, 16)
				.scale(0.8)
			.intoParent()
			.collect();
		challenge_button->setID("challenge-list-button");

		return true;
	}

	void openSearch(int type) {
		m_searchInput->onClickTrackNode(false);
		auto p = LevelBrowserLayer::create(getSearchObject(static_cast<SearchType>(type), ""));

		auto s = CCScene::create();
		s->addChild(p);
		CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5, s));
	}
};

class $(GameLevelManager) {
	void ProcessHttpRequest(gd::string gdurl, gd::string gdquery, gd::string unk, GJHttpType type) {
		std::string url(gdurl);
		std::string query(gdquery);

		if (url == "http://www.boomlings.com/database/getGJLevels21.php") {
			auto thing = atoi(query.substr(query.find("page=") + 5).c_str());
			if (query.find("type=3141") != std::string::npos) {
				url = std::string("http://absolllute.com/api/mega_hack/demonlist/page") + std::to_string(thing) + ".txt";
			} else if (query.find("type=3142") != std::string::npos) {
				url = std::string("http://absolllute.com/api/mega_hack/challengelist/page") + std::to_string(thing) + ".txt";
			}
		}

		GameLevelManager::ProcessHttpRequest(url, query, unk, type);
	}
};
