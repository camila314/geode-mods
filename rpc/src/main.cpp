#include <Geode.hpp>

USE_GEODE_NAMESPACE();

char const* sceneEnum[14] = {"uwu", "Idle", "Selecting level",
                                      "old_my_levels", "Watching level info",
                                      "Searching levels", "unused",
                                      "Browsing leaderboards",
                                      "Online", "Selecting official level",
                                      "Playing official level", "none", "none",
                                      "the_challenge"
                                      };
char const* modeEnum[7] = {"Cube", "Ship", "UFO", "Ball",
                           "Wave", "Robot", "Spider"};
char const* officialDifficulties[21] = {"easy", "easy", "normal",
                                        "normal", "hard", "hard", "harder",
                                        "harder", "harder", "insane", "insane",
                                        "insane", "insane", "hard-demon",
                                        "insane", "insane", "harder",
                                        "hard-demon", "harder", "hard-demon",
                                        "insane"};
char const* levelTypes[5] = {"none", "official", "editor", "saved", "online"};

char const* levelDifficulties[14] = {
    "Auto",
    "Easy",
    "Normal",
    "Hard",
    "Harder",
    "Insane",
    "Hard Demon",
    "Easy Demon",
    "Medium Demon",
    "Insane Demon",
    "Extreme Demon"
};

char const* imageDifficulties[14] = {"auto", "demon", "na", "n", "easy",
                                    "normal", "hard", "harder", "insane",
                                    "easy-demon", "medium-demon", "hard-demon",
                                    "insane-demon", "extreme-demon"};

class $modify(MenuLayer) {
	void onMoreGames(CCObject*) {
		FLAlertLayer::create("Geode", "Hello from my custom mod!", "OK")->show(); 
	} 
};
