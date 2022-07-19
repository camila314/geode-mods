#include <Geode.hpp>

USE_GEODE_NAMESPACE();

using namespace cocos2d;

class DebugWrapper : public CCMenu {
 protected:
 	CCSprite* m_selectedChild;
 public:
	static DebugWrapper* create() {
		auto ret = new DebugWrapper;
		ret->init();
		return ret;
	}

	bool init() override {
		CCMenu::init();
		m_selectedChild = nullptr;
		return true;
	}

	CCSprite* childForTouch(CCTouch* touch) {
		CCPoint touchLocation = touch->getLocation();

		if (m_pChildren && m_pChildren->count() > 0) {
		    CCObject* pObject = NULL;
		    CCARRAY_FOREACH(m_pChildren, pObject) {
		    	auto child = reinterpret_cast<CCSprite*>(pObject);

		        if (child->isVisible()) {
		            CCPoint local = child->convertToNodeSpace(touchLocation);
		            
		            CCRect r = child->getTextureRect();

		            r.origin = CCPointZero;

		            if (r.containsPoint(local)) 
		            	return child;
		        }
		    }
		}

		return nullptr;
	}

	bool ccTouchBegan(CCTouch* touch, CCEvent*) override {
		if (m_eState != kCCMenuStateWaiting || ! m_bVisible) {
		    return false;
		}

		for (CCNode *c = this->m_pParent; c != NULL; c = c->getParent()) {
		    if (c->isVisible() == false) {
		        return false;
		    }
		}

		m_selectedChild = this->childForTouch(touch);
		if (m_selectedChild) {
		    m_eState = kCCMenuStateTrackingTouch;
		    return true;
		}
		return false;
	}

	void ccTouchMoved(CCTouch* touch, CCEvent*) override {
		auto delta = touch->getLocationInView() - touch->getPreviousLocationInView();
		delta.y *= -1;
	
		if (m_selectedChild)
			m_selectedChild->setPosition(m_selectedChild->getPosition() + delta);
	}

	void ccTouchEnded(CCTouch* touch, CCEvent*) override {
		m_eState = kCCMenuStateWaiting;
		geode::log << m_selectedChild->getPosition();
		m_selectedChild = nullptr;
	}
};




namespace GameSheet3 {
	constexpr char const* GJLargeLock_001 = "GJLargeLock_001.png";
	constexpr char const* GJ_BPMOffBtn_001 = "GJ_BPMOffBtn_001.png";
	constexpr char const* GJ_BPMOnBtn_001 = "GJ_BPMOnBtn_001.png";
	constexpr char const* GJ_achBtn_001 = "GJ_achBtn_001.png";
	constexpr char const* GJ_arrow_01_001 = "GJ_arrow_01_001.png";
	constexpr char const* GJ_arrow_02_001 = "GJ_arrow_02_001.png";
	constexpr char const* GJ_arrow_03_001 = "GJ_arrow_03_001.png";
	constexpr char const* GJ_audioOffBtn_001 = "GJ_audioOffBtn_001.png";
	constexpr char const* GJ_audioOnBtn_001 = "GJ_audioOnBtn_001.png";
	constexpr char const* GJ_autoOffBtn_001 = "GJ_autoOffBtn_001.png";
	constexpr char const* GJ_autoOnBtn_001 = "GJ_autoOnBtn_001.png";
	constexpr char const* GJ_backBtn_001 = "GJ_backBtn_001.png";
	constexpr char const* GJ_bigDiamond_001 = "GJ_bigDiamond_001.png";
	constexpr char const* GJ_bigDiamond_glow_001 = "GJ_bigDiamond_glow_001.png";
	constexpr char const* GJ_bigDiamond_noShadow_001 = "GJ_bigDiamond_noShadow_001.png";
	constexpr char const* GJ_bigKey_001 = "GJ_bigKey_001.png";
	constexpr char const* GJ_bigKey_glow_001 = "GJ_bigKey_glow_001.png";
	constexpr char const* GJ_bigStar_001 = "GJ_bigStar_001.png";
	constexpr char const* GJ_bigStar_glow_001 = "GJ_bigStar_glow_001.png";
	constexpr char const* GJ_bigStar_noShadow_001 = "GJ_bigStar_noShadow_001.png";
	constexpr char const* GJ_cancelDownloadBtn_001 = "GJ_cancelDownloadBtn_001.png";
	constexpr char const* GJ_changeSongBtn_001 = "GJ_changeSongBtn_001.png";
	constexpr char const* GJ_chatBtn_001 = "GJ_chatBtn_001.png";
	constexpr char const* GJ_chatBtn_01_001 = "GJ_chatBtn_01_001.png";
	constexpr char const* GJ_chatBtn_02_001 = "GJ_chatBtn_02_001.png";
	constexpr char const* GJ_checkOff_001 = "GJ_checkOff_001.png";
	constexpr char const* GJ_checkOn_001 = "GJ_checkOn_001.png";
	constexpr char const* GJ_checkpointBtn_001 = "GJ_checkpointBtn_001.png";
	constexpr char const* GJ_chrSel_001 = "GJ_chrSel_001.png";
	constexpr char const* GJ_closeBtn_001 = "GJ_closeBtn_001.png";
	constexpr char const* GJ_coinsIcon2_001 = "GJ_coinsIcon2_001.png";
	constexpr char const* GJ_coinsIcon_001 = "GJ_coinsIcon_001.png";
	constexpr char const* GJ_coinsIcon_gray_001 = "GJ_coinsIcon_gray_001.png";
	constexpr char const* GJ_colorBtn_001 = "GJ_colorBtn_001.png";
	constexpr char const* GJ_commentSide2_001 = "GJ_commentSide2_001.png";
	constexpr char const* GJ_commentSide_001 = "GJ_commentSide_001.png";
	constexpr char const* GJ_commentTop2_001 = "GJ_commentTop2_001.png";
	constexpr char const* GJ_commentTop_001 = "GJ_commentTop_001.png";
	constexpr char const* GJ_completesIcon_001 = "GJ_completesIcon_001.png";
	constexpr char const* GJ_copyBtn2_001 = "GJ_copyBtn2_001.png";
	constexpr char const* GJ_copyBtn_001 = "GJ_copyBtn_001.png";
	constexpr char const* GJ_copyStateBtn_001 = "GJ_copyStateBtn_001.png";
	constexpr char const* GJ_createLinesBtn_001 = "GJ_createLinesBtn_001.png";
	constexpr char const* GJ_creatorBtn_001 = "GJ_creatorBtn_001.png";
	constexpr char const* GJ_dailyRewardBtn_001 = "GJ_dailyRewardBtn_001.png";
	constexpr char const* GJ_deSelBtn2_001 = "GJ_deSelBtn2_001.png";
	constexpr char const* GJ_deSelBtn_001 = "GJ_deSelBtn_001.png";
	constexpr char const* GJ_deleteAllIcon_001 = "GJ_deleteAllIcon_001.png";
	constexpr char const* GJ_deleteBtn_001 = "GJ_deleteBtn_001.png";
	constexpr char const* GJ_deleteIcon_001 = "GJ_deleteIcon_001.png";
	constexpr char const* GJ_deleteServerBtn_001 = "GJ_deleteServerBtn_001.png";
	constexpr char const* GJ_deleteSongBtn_001 = "GJ_deleteSongBtn_001.png";
	constexpr char const* GJ_demonIcon_001 = "GJ_demonIcon_001.png";
	constexpr char const* GJ_diamondsIcon_001 = "GJ_diamondsIcon_001.png";
	constexpr char const* GJ_dislikeBtn_001 = "GJ_dislikeBtn_001.png";
	constexpr char const* GJ_dislikesIcon_001 = "GJ_dislikesIcon_001.png";
	constexpr char const* GJ_downloadBtn_001 = "GJ_downloadBtn_001.png";
	constexpr char const* GJ_downloadsIcon_001 = "GJ_downloadsIcon_001.png";
	constexpr char const* GJ_duplicateBtn_001 = "GJ_duplicateBtn_001.png";
	constexpr char const* GJ_duplicateLockedBtn_001 = "GJ_duplicateLockedBtn_001.png";
	constexpr char const* GJ_duplicateObjectBtn2_001 = "GJ_duplicateObjectBtn2_001.png";
	constexpr char const* GJ_duplicateObjectBtn_001 = "GJ_duplicateObjectBtn_001.png";
	constexpr char const* GJ_editBtn_001 = "GJ_editBtn_001.png";
	constexpr char const* GJ_editHSVBtn2_001 = "GJ_editHSVBtn2_001.png";
	constexpr char const* GJ_editObjBtn3_001 = "GJ_editObjBtn3_001.png";
	constexpr char const* GJ_editObjBtn4_001 = "GJ_editObjBtn4_001.png";
	constexpr char const* GJ_epicCoin_001 = "GJ_epicCoin_001.png";
	constexpr char const* GJ_everyplayBtn_001 = "GJ_everyplayBtn_001.png";
	constexpr char const* GJ_extendedIcon_001 = "GJ_extendedIcon_001.png";
	constexpr char const* GJ_featuredCoin_001 = "GJ_featuredCoin_001.png";
	constexpr char const* GJ_featuredIcon_001 = "GJ_featuredIcon_001.png";
	constexpr char const* GJ_followTxt_001 = "GJ_followTxt_001.png";
	constexpr char const* GJ_freeLevelsBtn_001 = "GJ_freeLevelsBtn_001.png";
	constexpr char const* GJ_freeStuffBtn_001 = "GJ_freeStuffBtn_001.png";
	constexpr char const* GJ_fullBtn_001 = "GJ_fullBtn_001.png";
	constexpr char const* GJ_fxOffBtn_001 = "GJ_fxOffBtn_001.png";
	constexpr char const* GJ_fxOnBtn_001 = "GJ_fxOnBtn_001.png";
	constexpr char const* GJ_garageBtn_001 = "GJ_garageBtn_001.png";
	constexpr char const* GJ_getSongInfoBtn_001 = "GJ_getSongInfoBtn_001.png";
	constexpr char const* GJ_gkBtn_001 = "GJ_gkBtn_001.png";
	constexpr char const* GJ_goToLayerBtn_001 = "GJ_goToLayerBtn_001.png";
	constexpr char const* GJ_gpBtn_001 = "GJ_gpBtn_001.png";
	constexpr char const* GJ_gpgBtn_001 = "GJ_gpgBtn_001.png";
	constexpr char const* GJ_groupIDBtn2_001 = "GJ_groupIDBtn2_001.png";
	constexpr char const* GJ_groupIDBtn_001 = "GJ_groupIDBtn_001.png";
	constexpr char const* GJ_hammerIcon_001 = "GJ_hammerIcon_001.png";
	constexpr char const* GJ_helpBtn2_001 = "GJ_helpBtn2_001.png";
	constexpr char const* GJ_helpBtn_001 = "GJ_helpBtn_001.png";
	constexpr char const* GJ_hsv2Btn_001 = "GJ_hsv2Btn_001.png";
	constexpr char const* GJ_hsvBtn_001 = "GJ_hsvBtn_001.png";
	constexpr char const* GJ_infoBtn_001 = "GJ_infoBtn_001.png";
	constexpr char const* GJ_infoIcon_001 = "GJ_infoIcon_001.png";
	constexpr char const* GJ_levelComplete_001 = "GJ_levelComplete_001.png";
	constexpr char const* GJ_levelLeaderboardBtn_001 = "GJ_levelLeaderboardBtn_001.png";
	constexpr char const* GJ_like2Btn2_001 = "GJ_like2Btn2_001.png";
	constexpr char const* GJ_like2Btn_001 = "GJ_like2Btn_001.png";
	constexpr char const* GJ_likeBtn2_001 = "GJ_likeBtn2_001.png";
	constexpr char const* GJ_likeBtn_001 = "GJ_likeBtn_001.png";
	constexpr char const* GJ_likesIcon_001 = "GJ_likesIcon_001.png";
	constexpr char const* GJ_lockGray_001 = "GJ_lockGray_001.png";
	constexpr char const* GJ_lock_001 = "GJ_lock_001.png";
	constexpr char const* GJ_lock_open_001 = "GJ_lock_open_001.png";
	constexpr char const* GJ_longBtn01_001 = "GJ_longBtn01_001.png";
	constexpr char const* GJ_longBtn02_001 = "GJ_longBtn02_001.png";
	constexpr char const* GJ_longBtn03_001 = "GJ_longBtn03_001.png";
	constexpr char const* GJ_longBtn04_001 = "GJ_longBtn04_001.png";
	constexpr char const* GJ_longBtn05_001 = "GJ_longBtn05_001.png";
	constexpr char const* GJ_lvlEditWorld_001 = "GJ_lvlEditWorld_001.png";
	constexpr char const* GJ_lvlEdit_001 = "GJ_lvlEdit_001.png";
	constexpr char const* GJ_menuBtn_001 = "GJ_menuBtn_001.png";
	constexpr char const* GJ_moreGamesBtn_001 = "GJ_moreGamesBtn_001.png";
	constexpr char const* GJ_musicOffBtn_001 = "GJ_musicOffBtn_001.png";
	constexpr char const* GJ_musicOnBtn_001 = "GJ_musicOnBtn_001.png";
	constexpr char const* GJ_myLevelsTxt_001 = "GJ_myLevelsTxt_001.png";
	constexpr char const* GJ_myServerBtn_001 = "GJ_myServerBtn_001.png";
	constexpr char const* GJ_nameTxt_001 = "GJ_nameTxt_001.png";
	constexpr char const* GJ_newBest_001 = "GJ_newBest_001.png";
	constexpr char const* GJ_newBtn_001 = "GJ_newBtn_001.png";
	constexpr char const* GJ_ngBtn_001 = "GJ_ngBtn_001.png";
	constexpr char const* GJ_normalBtn_001 = "GJ_normalBtn_001.png";
	constexpr char const* GJ_noteIcon_001 = "GJ_noteIcon_001.png";
	constexpr char const* GJ_optionsBtn02_001 = "GJ_optionsBtn02_001.png";
	constexpr char const* GJ_optionsBtn_001 = "GJ_optionsBtn_001.png";
	constexpr char const* GJ_optionsTxt_001 = "GJ_optionsTxt_001.png";
	constexpr char const* GJ_orderUpBtn_001 = "GJ_orderUpBtn_001.png";
	constexpr char const* GJ_pasteBtn2_001 = "GJ_pasteBtn2_001.png";
	constexpr char const* GJ_pasteBtn_001 = "GJ_pasteBtn_001.png";
	constexpr char const* GJ_pasteColorBtn_001 = "GJ_pasteColorBtn_001.png";
	constexpr char const* GJ_pasteStateBtn_001 = "GJ_pasteStateBtn_001.png";
	constexpr char const* GJ_pauseBtn_001 = "GJ_pauseBtn_001.png";
	constexpr char const* GJ_pauseBtn_clean_001 = "GJ_pauseBtn_clean_001.png";
	constexpr char const* GJ_pauseEditorBtn_001 = "GJ_pauseEditorBtn_001.png";
	constexpr char const* GJ_playBtn2_001 = "GJ_playBtn2_001.png";
	constexpr char const* GJ_playBtn_001 = "GJ_playBtn_001.png";
	constexpr char const* GJ_playEditorBtn_001 = "GJ_playEditorBtn_001.png";
	constexpr char const* GJ_playMusicBtn_001 = "GJ_playMusicBtn_001.png";
	constexpr char const* GJ_plus2Btn_001 = "GJ_plus2Btn_001.png";
	constexpr char const* GJ_plus3Btn_001 = "GJ_plus3Btn_001.png";
	constexpr char const* GJ_plusBtn_001 = "GJ_plusBtn_001.png";
	constexpr char const* GJ_practiceBtn_001 = "GJ_practiceBtn_001.png";
	constexpr char const* GJ_practiceComplete_001 = "GJ_practiceComplete_001.png";
	constexpr char const* GJ_practiceTxt_001 = "GJ_practiceTxt_001.png";
	constexpr char const* GJ_profileButton_001 = "GJ_profileButton_001.png";
	constexpr char const* GJ_rateDiffBtn2_001 = "GJ_rateDiffBtn2_001.png";
	constexpr char const* GJ_rateDiffBtnMod_001 = "GJ_rateDiffBtnMod_001.png";
	constexpr char const* GJ_rateDiffBtn_001 = "GJ_rateDiffBtn_001.png";
	constexpr char const* GJ_redoBtn_001 = "GJ_redoBtn_001.png";
	constexpr char const* GJ_removeCheckBtn_001 = "GJ_removeCheckBtn_001.png";
	constexpr char const* GJ_replayBtn_001 = "GJ_replayBtn_001.png";
	constexpr char const* GJ_reportBtn_001 = "GJ_reportBtn_001.png";
	constexpr char const* GJ_resetBtn_001 = "GJ_resetBtn_001.png";
	constexpr char const* GJ_rewardBtn_001 = "GJ_rewardBtn_001.png";
	constexpr char const* GJ_rotationControlBtn01_001 = "GJ_rotationControlBtn01_001.png";
	constexpr char const* GJ_rotationControlBtn02_001 = "GJ_rotationControlBtn02_001.png";
	constexpr char const* GJ_sDownloadIcon_001 = "GJ_sDownloadIcon_001.png";
	constexpr char const* GJ_sFollowedIcon_001 = "GJ_sFollowedIcon_001.png";
	constexpr char const* GJ_sFriendsIcon_001 = "GJ_sFriendsIcon_001.png";
	constexpr char const* GJ_sLikeIcon_001 = "GJ_sLikeIcon_001.png";
	constexpr char const* GJ_sMagicIcon_001 = "GJ_sMagicIcon_001.png";
	constexpr char const* GJ_sRecentIcon_001 = "GJ_sRecentIcon_001.png";
	constexpr char const* GJ_sStarsIcon_001 = "GJ_sStarsIcon_001.png";
	constexpr char const* GJ_sTrendingIcon_001 = "GJ_sTrendingIcon_001.png";
	constexpr char const* GJ_savedSongsBtn_001 = "GJ_savedSongsBtn_001.png";
	constexpr char const* GJ_secretLock_001 = "GJ_secretLock_001.png";
	constexpr char const* GJ_selectSongBtn_001 = "GJ_selectSongBtn_001.png";
	constexpr char const* GJ_selectSongOnBtn_001 = "GJ_selectSongOnBtn_001.png";
	constexpr char const* GJ_select_001 = "GJ_select_001.png";
	constexpr char const* GJ_shardsBtn_001 = "GJ_shardsBtn_001.png";
	constexpr char const* GJ_shareBtn_001 = "GJ_shareBtn_001.png";
	constexpr char const* GJ_sideArt_001 = "GJ_sideArt_001.png";
	constexpr char const* GJ_smallModeIcon_001 = "GJ_smallModeIcon_001.png";
	constexpr char const* GJ_starBtn2_001 = "GJ_starBtn2_001.png";
	constexpr char const* GJ_starBtnMod_001 = "GJ_starBtnMod_001.png";
	constexpr char const* GJ_starBtn_001 = "GJ_starBtn_001.png";
	constexpr char const* GJ_starsIcon_001 = "GJ_starsIcon_001.png";
	constexpr char const* GJ_starsIcon_gray_001 = "GJ_starsIcon_gray_001.png";
	constexpr char const* GJ_statsBtn_001 = "GJ_statsBtn_001.png";
	constexpr char const* GJ_stopEditorBtn_001 = "GJ_stopEditorBtn_001.png";
	constexpr char const* GJ_stopMusicBtn_001 = "GJ_stopMusicBtn_001.png";
	constexpr char const* GJ_stuffTxt_001 = "GJ_stuffTxt_001.png";
	constexpr char const* GJ_tabOff_001 = "GJ_tabOff_001.png";
	constexpr char const* GJ_tabOn_001 = "GJ_tabOn_001.png";
	constexpr char const* GJ_table_bottom_001 = "GJ_table_bottom_001.png";
	constexpr char const* GJ_table_side_001 = "GJ_table_side_001.png";
	constexpr char const* GJ_table_top02_001 = "GJ_table_top02_001.png";
	constexpr char const* GJ_table_top_001 = "GJ_table_top_001.png";
	constexpr char const* GJ_timeIcon_001 = "GJ_timeIcon_001.png";
	constexpr char const* GJ_topBar_001 = "GJ_topBar_001.png";
	constexpr char const* GJ_trailerBtn_001 = "GJ_trailerBtn_001.png";
	constexpr char const* GJ_trashBtn_001 = "GJ_trashBtn_001.png";
	constexpr char const* GJ_twitchTxt_001 = "GJ_twitchTxt_001.png";
	constexpr char const* GJ_twitterTxt_001 = "GJ_twitterTxt_001.png";
	constexpr char const* GJ_undoBtn_001 = "GJ_undoBtn_001.png";
	constexpr char const* GJ_unlockTxt_001 = "GJ_unlockTxt_001.png";
	constexpr char const* GJ_updateBtn_001 = "GJ_updateBtn_001.png";
	constexpr char const* GJ_viewProfileTxt_001 = "GJ_viewProfileTxt_001.png";
	constexpr char const* GJ_yourProfileTxt_001 = "GJ_yourProfileTxt_001.png";
	constexpr char const* GJ_youtubeTxt_001 = "GJ_youtubeTxt_001.png";
	constexpr char const* GJ_zoomInBtn_001 = "GJ_zoomInBtn_001.png";
	constexpr char const* GJ_zoomOutBtn_001 = "GJ_zoomOutBtn_001.png";
	constexpr char const* accountBtn_blocked_001 = "accountBtn_blocked_001.png";
	constexpr char const* accountBtn_friends_001 = "accountBtn_friends_001.png";
	constexpr char const* accountBtn_messages_001 = "accountBtn_messages_001.png";
	constexpr char const* accountBtn_messagessent_001 = "accountBtn_messagessent_001.png";
	constexpr char const* accountBtn_myLevels_001 = "accountBtn_myLevels_001.png";
	constexpr char const* accountBtn_pendingRequest_001 = "accountBtn_pendingRequest_001.png";
	constexpr char const* accountBtn_pending_001 = "accountBtn_pending_001.png";
	constexpr char const* accountBtn_removeFriend_001 = "accountBtn_removeFriend_001.png";
	constexpr char const* accountBtn_requests_001 = "accountBtn_requests_001.png";
	constexpr char const* accountBtn_settings_001 = "accountBtn_settings_001.png";
	constexpr char const* achievementGlow_001 = "achievementGlow_001.png";
	constexpr char const* bgIcon_01_001 = "bgIcon_01_001.png";
	constexpr char const* bgIcon_02_001 = "bgIcon_02_001.png";
	constexpr char const* bgIcon_03_001 = "bgIcon_03_001.png";
	constexpr char const* bgIcon_04_001 = "bgIcon_04_001.png";
	constexpr char const* bgIcon_05_001 = "bgIcon_05_001.png";
	constexpr char const* bgIcon_06_001 = "bgIcon_06_001.png";
	constexpr char const* bgIcon_07_001 = "bgIcon_07_001.png";
	constexpr char const* bgIcon_08_001 = "bgIcon_08_001.png";
	constexpr char const* bgIcon_09_001 = "bgIcon_09_001.png";
	constexpr char const* bgIcon_10_001 = "bgIcon_10_001.png";
	constexpr char const* bgIcon_11_001 = "bgIcon_11_001.png";
	constexpr char const* bgIcon_12_001 = "bgIcon_12_001.png";
	constexpr char const* bgIcon_13_001 = "bgIcon_13_001.png";
	constexpr char const* bgIcon_14_001 = "bgIcon_14_001.png";
	constexpr char const* bgIcon_15_001 = "bgIcon_15_001.png";
	constexpr char const* bgIcon_16_001 = "bgIcon_16_001.png";
	constexpr char const* bgIcon_17_001 = "bgIcon_17_001.png";
	constexpr char const* bgIcon_18_001 = "bgIcon_18_001.png";
	constexpr char const* bgIcon_19_001 = "bgIcon_19_001.png";
	constexpr char const* bgIcon_20_001 = "bgIcon_20_001.png";
	constexpr char const* bonusShardLabel_001 = "bonusShardLabel_001.png";
	constexpr char const* bonusShardSmall_001 = "bonusShardSmall_001.png";
	constexpr char const* btn_chatHistory_001 = "btn_chatHistory_001.png";
	constexpr char const* cocos2DxLogo = "cocos2DxLogo.png";
	constexpr char const* collaborationIcon_001 = "collaborationIcon_001.png";
	constexpr char const* communityCreditsBtn_001 = "communityCreditsBtn_001.png";
	constexpr char const* communityIcon_01_001 = "communityIcon_01_001.png";
	constexpr char const* communityIcon_02_001 = "communityIcon_02_001.png";
	constexpr char const* communityIcon_03_001 = "communityIcon_03_001.png";
	constexpr char const* controllerBtn_A_001 = "controllerBtn_A_001.png";
	constexpr char const* controllerBtn_B_001 = "controllerBtn_B_001.png";
	constexpr char const* controllerBtn_Back_001 = "controllerBtn_Back_001.png";
	constexpr char const* controllerBtn_DPad_Down_001 = "controllerBtn_DPad_Down_001.png";
	constexpr char const* controllerBtn_DPad_Left_001 = "controllerBtn_DPad_Left_001.png";
	constexpr char const* controllerBtn_DPad_Right_001 = "controllerBtn_DPad_Right_001.png";
	constexpr char const* controllerBtn_DPad_Up_001 = "controllerBtn_DPad_Up_001.png";
	constexpr char const* controllerBtn_LThumb_001 = "controllerBtn_LThumb_001.png";
	constexpr char const* controllerBtn_RThumb_001 = "controllerBtn_RThumb_001.png";
	constexpr char const* controllerBtn_Start_001 = "controllerBtn_Start_001.png";
	constexpr char const* controllerBtn_X_001 = "controllerBtn_X_001.png";
	constexpr char const* controllerBtn_Y_001 = "controllerBtn_Y_001.png";
	constexpr char const* creators_tab_off_001 = "creators_tab_off_001.png";
	constexpr char const* creators_tab_on_001 = "creators_tab_on_001.png";
	constexpr char const* currencyOrbIcon_001 = "currencyOrbIcon_001.png";
	constexpr char const* currencyOrb_001 = "currencyOrb_001.png";
	constexpr char const* dailyLevelCorner_001 = "dailyLevelCorner_001.png";
	constexpr char const* dailyLevelLabel_001 = "dailyLevelLabel_001.png";
	constexpr char const* deleteFilter_custom_001 = "deleteFilter_custom_001.png";
	constexpr char const* deleteFilter_details_001 = "deleteFilter_details_001.png";
	constexpr char const* deleteFilter_none_001 = "deleteFilter_none_001.png";
	constexpr char const* deleteFilter_static_001 = "deleteFilter_static_001.png";
	constexpr char const* developedBy_001 = "developedBy_001.png";
	constexpr char const* diamond_small01_001 = "diamond_small01_001.png";
	constexpr char const* diffIcon_01_btn_001 = "diffIcon_01_btn_001.png";
	constexpr char const* diffIcon_02_btn_001 = "diffIcon_02_btn_001.png";
	constexpr char const* diffIcon_03_btn_001 = "diffIcon_03_btn_001.png";
	constexpr char const* diffIcon_04_btn_001 = "diffIcon_04_btn_001.png";
	constexpr char const* diffIcon_05_btn_001 = "diffIcon_05_btn_001.png";
	constexpr char const* diffIcon_06_btn_001 = "diffIcon_06_btn_001.png";
	constexpr char const* difficultySelected_001 = "difficultySelected_001.png";
	constexpr char const* difficulty_00_btn_001 = "difficulty_00_btn_001.png";
	constexpr char const* difficulty_01_btn_001 = "difficulty_01_btn_001.png";
	constexpr char const* difficulty_02_btn_001 = "difficulty_02_btn_001.png";
	constexpr char const* difficulty_03_btn_001 = "difficulty_03_btn_001.png";
	constexpr char const* difficulty_04_btn_001 = "difficulty_04_btn_001.png";
	constexpr char const* difficulty_05_btn_001 = "difficulty_05_btn_001.png";
	constexpr char const* difficulty_06_btn2_001 = "difficulty_06_btn2_001.png";
	constexpr char const* difficulty_06_btn_001 = "difficulty_06_btn_001.png";
	constexpr char const* difficulty_07_btn2_001 = "difficulty_07_btn2_001.png";
	constexpr char const* difficulty_07_btn_001 = "difficulty_07_btn_001.png";
	constexpr char const* difficulty_08_btn2_001 = "difficulty_08_btn2_001.png";
	constexpr char const* difficulty_08_btn_001 = "difficulty_08_btn_001.png";
	constexpr char const* difficulty_09_btn2_001 = "difficulty_09_btn2_001.png";
	constexpr char const* difficulty_09_btn_001 = "difficulty_09_btn_001.png";
	constexpr char const* difficulty_10_btn2_001 = "difficulty_10_btn2_001.png";
	constexpr char const* difficulty_10_btn_001 = "difficulty_10_btn_001.png";
	constexpr char const* difficulty_auto_btn_001 = "difficulty_auto_btn_001.png";
	constexpr char const* edit_addCBtn_001 = "edit_addCBtn_001.png";
	constexpr char const* edit_buildBtn_001 = "edit_buildBtn_001.png";
	constexpr char const* edit_buildSBtn_001 = "edit_buildSBtn_001.png";
	constexpr char const* edit_ccwBtn_001 = "edit_ccwBtn_001.png";
	constexpr char const* edit_cwBtn_001 = "edit_cwBtn_001.png";
	constexpr char const* edit_delBtnSmall_001 = "edit_delBtnSmall_001.png";
	constexpr char const* edit_delBtn_001 = "edit_delBtn_001.png";
	constexpr char const* edit_delCBtn_001 = "edit_delCBtn_001.png";
	constexpr char const* edit_deleteBtn_001 = "edit_deleteBtn_001.png";
	constexpr char const* edit_deleteSBtn_001 = "edit_deleteSBtn_001.png";
	constexpr char const* edit_deselectBtn_001 = "edit_deselectBtn_001.png";
	constexpr char const* edit_downBtn2_001 = "edit_downBtn2_001.png";
	constexpr char const* edit_downBtn3_001 = "edit_downBtn3_001.png";
	constexpr char const* edit_downBtn_001 = "edit_downBtn_001.png";
	constexpr char const* edit_editBtn_001 = "edit_editBtn_001.png";
	constexpr char const* edit_editSBtn_001 = "edit_editSBtn_001.png";
	constexpr char const* edit_enableRotateBtn_001 = "edit_enableRotateBtn_001.png";
	constexpr char const* edit_flipXBtn_001 = "edit_flipXBtn_001.png";
	constexpr char const* edit_flipYBtn_001 = "edit_flipYBtn_001.png";
	constexpr char const* edit_freeMoveBtn_001 = "edit_freeMoveBtn_001.png";
	constexpr char const* edit_freeRotateBtn_001 = "edit_freeRotateBtn_001.png";
	constexpr char const* edit_leftBtn2_001 = "edit_leftBtn2_001.png";
	constexpr char const* edit_leftBtn3_001 = "edit_leftBtn3_001.png";
	constexpr char const* edit_leftBtn_001 = "edit_leftBtn_001.png";
	constexpr char const* edit_rightBtn2_001 = "edit_rightBtn2_001.png";
	constexpr char const* edit_rightBtn3_001 = "edit_rightBtn3_001.png";
	constexpr char const* edit_rightBtn_001 = "edit_rightBtn_001.png";
	constexpr char const* edit_rotate45lBtn_001 = "edit_rotate45lBtn_001.png";
	constexpr char const* edit_rotate45rBtn_001 = "edit_rotate45rBtn_001.png";
	constexpr char const* edit_rotateSnapBtn_001 = "edit_rotateSnapBtn_001.png";
	constexpr char const* edit_snapBtn_001 = "edit_snapBtn_001.png";
	constexpr char const* edit_swipeBtn_001 = "edit_swipeBtn_001.png";
	constexpr char const* edit_upBtn2_001 = "edit_upBtn2_001.png";
	constexpr char const* edit_upBtn3_001 = "edit_upBtn3_001.png";
	constexpr char const* edit_upBtn_001 = "edit_upBtn_001.png";
	constexpr char const* edit_vLine_001 = "edit_vLine_001.png";
	constexpr char const* exMark_001 = "exMark_001.png";
	constexpr char const* explosionIcon_01_001 = "explosionIcon_01_001.png";
	constexpr char const* explosionIcon_02_001 = "explosionIcon_02_001.png";
	constexpr char const* explosionIcon_03_001 = "explosionIcon_03_001.png";
	constexpr char const* explosionIcon_04_001 = "explosionIcon_04_001.png";
	constexpr char const* explosionIcon_05_001 = "explosionIcon_05_001.png";
	constexpr char const* explosionIcon_06_001 = "explosionIcon_06_001.png";
	constexpr char const* explosionIcon_07_001 = "explosionIcon_07_001.png";
	constexpr char const* explosionIcon_08_001 = "explosionIcon_08_001.png";
	constexpr char const* explosionIcon_09_001 = "explosionIcon_09_001.png";
	constexpr char const* explosionIcon_10_001 = "explosionIcon_10_001.png";
	constexpr char const* explosionIcon_11_001 = "explosionIcon_11_001.png";
	constexpr char const* explosionIcon_12_001 = "explosionIcon_12_001.png";
	constexpr char const* explosionIcon_13_001 = "explosionIcon_13_001.png";
	constexpr char const* explosionIcon_14_001 = "explosionIcon_14_001.png";
	constexpr char const* explosionIcon_15_001 = "explosionIcon_15_001.png";
	constexpr char const* explosionIcon_16_001 = "explosionIcon_16_001.png";
	constexpr char const* explosionIcon_17_001 = "explosionIcon_17_001.png";
	constexpr char const* featuredLabel_001 = "featuredLabel_001.png";
	constexpr char const* fireShardBig_001 = "fireShardBig_001.png";
	constexpr char const* fireShardLabel_001 = "fireShardLabel_001.png";
	constexpr char const* fireShardSmall_001 = "fireShardSmall_001.png";
	constexpr char const* friends_tab_off_001 = "friends_tab_off_001.png";
	constexpr char const* friends_tab_on_001 = "friends_tab_on_001.png";
	constexpr char const* gIcon_01_001 = "gIcon_01_001.png";
	constexpr char const* gIcon_02_001 = "gIcon_02_001.png";
	constexpr char const* gIcon_03_001 = "gIcon_03_001.png";
	constexpr char const* gIcon_04_001 = "gIcon_04_001.png";
	constexpr char const* gIcon_05_001 = "gIcon_05_001.png";
	constexpr char const* gIcon_06_001 = "gIcon_06_001.png";
	constexpr char const* gIcon_07_001 = "gIcon_07_001.png";
	constexpr char const* gIcon_08_001 = "gIcon_08_001.png";
	constexpr char const* gIcon_09_001 = "gIcon_09_001.png";
	constexpr char const* gIcon_10_001 = "gIcon_10_001.png";
	constexpr char const* gIcon_11_001 = "gIcon_11_001.png";
	constexpr char const* gIcon_12_001 = "gIcon_12_001.png";
	constexpr char const* gIcon_13_001 = "gIcon_13_001.png";
	constexpr char const* gIcon_14_001 = "gIcon_14_001.png";
	constexpr char const* gIcon_15_001 = "gIcon_15_001.png";
	constexpr char const* gIcon_16_001 = "gIcon_16_001.png";
	constexpr char const* gIcon_17_001 = "gIcon_17_001.png";
	constexpr char const* garageRope_001 = "garageRope_001.png";
	constexpr char const* gauntletCorner_001 = "gauntletCorner_001.png";
	constexpr char const* gjItem_01_001 = "gjItem_01_001.png";
	constexpr char const* gjItem_02_001 = "gjItem_02_001.png";
	constexpr char const* gjItem_03_001 = "gjItem_03_001.png";
	constexpr char const* gjItem_04_001 = "gjItem_04_001.png";
	constexpr char const* gjItem_05_001 = "gjItem_05_001.png";
	constexpr char const* gj_ballBtn_off_001 = "gj_ballBtn_off_001.png";
	constexpr char const* gj_ballBtn_on_001 = "gj_ballBtn_on_001.png";
	constexpr char const* gj_birdBtn_off_001 = "gj_birdBtn_off_001.png";
	constexpr char const* gj_birdBtn_on_001 = "gj_birdBtn_on_001.png";
	constexpr char const* gj_dailyCrown_001 = "gj_dailyCrown_001.png";
	constexpr char const* gj_dartBtn_off_001 = "gj_dartBtn_off_001.png";
	constexpr char const* gj_dartBtn_on_001 = "gj_dartBtn_on_001.png";
	constexpr char const* gj_explosionBtn_off_001 = "gj_explosionBtn_off_001.png";
	constexpr char const* gj_explosionBtn_on_001 = "gj_explosionBtn_on_001.png";
	constexpr char const* gj_fbIcon_001 = "gj_fbIcon_001.png";
	constexpr char const* gj_findBtnOff_001 = "gj_findBtnOff_001.png";
	constexpr char const* gj_findBtn_001 = "gj_findBtn_001.png";
	constexpr char const* gj_folderBtn_001 = "gj_folderBtn_001.png";
	constexpr char const* gj_globalRankTxt_001 = "gj_globalRankTxt_001.png";
	constexpr char const* gj_heartOff_001 = "gj_heartOff_001.png";
	constexpr char const* gj_heartOn_001 = "gj_heartOn_001.png";
	constexpr char const* gj_iconBtn_off_001 = "gj_iconBtn_off_001.png";
	constexpr char const* gj_iconBtn_on_001 = "gj_iconBtn_on_001.png";
	constexpr char const* gj_linkBtnOff_001 = "gj_linkBtnOff_001.png";
	constexpr char const* gj_linkBtn_001 = "gj_linkBtn_001.png";
	constexpr char const* gj_robotBtn_off_001 = "gj_robotBtn_off_001.png";
	constexpr char const* gj_robotBtn_on_001 = "gj_robotBtn_on_001.png";
	constexpr char const* gj_shipBtn_off_001 = "gj_shipBtn_off_001.png";
	constexpr char const* gj_shipBtn_on_001 = "gj_shipBtn_on_001.png";
	constexpr char const* gj_spiderBtn_off_001 = "gj_spiderBtn_off_001.png";
	constexpr char const* gj_spiderBtn_on_001 = "gj_spiderBtn_on_001.png";
	constexpr char const* gj_streakBtn_off_001 = "gj_streakBtn_off_001.png";
	constexpr char const* gj_streakBtn_on_001 = "gj_streakBtn_on_001.png";
	constexpr char const* gj_twIcon_001 = "gj_twIcon_001.png";
	constexpr char const* gj_twitchIcon_001 = "gj_twitchIcon_001.png";
	constexpr char const* gj_weeklyCrown_001 = "gj_weeklyCrown_001.png";
	constexpr char const* gj_ytIcon_001 = "gj_ytIcon_001.png";
	constexpr char const* global_tab_off_001 = "global_tab_off_001.png";
	constexpr char const* global_tab_on_001 = "global_tab_on_001.png";
	constexpr char const* gplusSignIn_001 = "gplusSignIn_001.png";
	constexpr char const* gplusSignOut_001 = "gplusSignOut_001.png";
	constexpr char const* groundSquareShadow_001 = "groundSquareShadow_001.png";
	constexpr char const* hallOfFameLabel_001 = "hallOfFameLabel_001.png";
	constexpr char const* highObjectIcon_001 = "highObjectIcon_001.png";
	constexpr char const* iceShardBig_001 = "iceShardBig_001.png";
	constexpr char const* iceShardLabel_001 = "iceShardLabel_001.png";
	constexpr char const* iceShardSmall_001 = "iceShardSmall_001.png";
	constexpr char const* lavaShardBig_001 = "lavaShardBig_001.png";
	constexpr char const* lavaShardLabel_001 = "lavaShardLabel_001.png";
	constexpr char const* lavaShardSmall_001 = "lavaShardSmall_001.png";
	constexpr char const* levelLeaderboard_friendsBtn_001 = "levelLeaderboard_friendsBtn_001.png";
	constexpr char const* levelLeaderboard_globalBtn_001 = "levelLeaderboard_globalBtn_001.png";
	constexpr char const* levelLeaderboard_globalWeeklyBtn_001 = "levelLeaderboard_globalWeeklyBtn_001.png";
	constexpr char const* miniSkull_001 = "miniSkull_001.png";
	constexpr char const* modBadge_01_001 = "modBadge_01_001.png";
	constexpr char const* modBadge_02_001 = "modBadge_02_001.png";
	constexpr char const* navArrowBtn_001 = "navArrowBtn_001.png";
	constexpr char const* playerSquare_001 = "playerSquare_001.png";
	constexpr char const* player_special_01_001 = "player_special_01_001.png";
	constexpr char const* player_special_02_001 = "player_special_02_001.png";
	constexpr char const* player_special_03_001 = "player_special_03_001.png";
	constexpr char const* player_special_04_001 = "player_special_04_001.png";
	constexpr char const* player_special_05_001 = "player_special_05_001.png";
	constexpr char const* player_special_06_001 = "player_special_06_001.png";
	constexpr char const* player_special_07_001 = "player_special_07_001.png";
	constexpr char const* poisonShardBig_001 = "poisonShardBig_001.png";
	constexpr char const* poisonShardLabel_001 = "poisonShardLabel_001.png";
	constexpr char const* poisonShardSmall_001 = "poisonShardSmall_001.png";
	constexpr char const* poweredBy_001 = "poweredBy_001.png";
	constexpr char const* rankIcon_1_001 = "rankIcon_1_001.png";
	constexpr char const* rankIcon_all_001 = "rankIcon_all_001.png";
	constexpr char const* rankIcon_top1000_001 = "rankIcon_top1000_001.png";
	constexpr char const* rankIcon_top100_001 = "rankIcon_top100_001.png";
	constexpr char const* rankIcon_top10_001 = "rankIcon_top10_001.png";
	constexpr char const* rankIcon_top200_001 = "rankIcon_top200_001.png";
	constexpr char const* rankIcon_top500_001 = "rankIcon_top500_001.png";
	constexpr char const* rankIcon_top50_001 = "rankIcon_top50_001.png";
	constexpr char const* rewardCorner_001 = "rewardCorner_001.png";
	constexpr char const* rewardsLabel_001 = "rewardsLabel_001.png";
	constexpr char const* robtoplogo_small = "robtoplogo_small.png";
	constexpr char const* secretCoinUI2_001 = "secretCoinUI2_001.png";
	constexpr char const* secretCoinUI_001 = "secretCoinUI_001.png";
	constexpr char const* secretDoorBtn2_closed_001 = "secretDoorBtn2_closed_001.png";
	constexpr char const* secretDoorBtn2_open_001 = "secretDoorBtn2_open_001.png";
	constexpr char const* secretDoorBtn_closed_001 = "secretDoorBtn_closed_001.png";
	constexpr char const* secretDoorBtn_open_001 = "secretDoorBtn_open_001.png";
	constexpr char const* shadowShardBig_001 = "shadowShardBig_001.png";
	constexpr char const* shadowShardLabel_001 = "shadowShardLabel_001.png";
	constexpr char const* shadowShardSmall_001 = "shadowShardSmall_001.png";
	constexpr char const* shardShadow_001 = "shardShadow_001.png";
	constexpr char const* shard_glow_001 = "shard_glow_001.png";
	constexpr char const* shardsOfPowerLabel_001 = "shardsOfPowerLabel_001.png";
	constexpr char const* shineBurst_001 = "shineBurst_001.png";
	constexpr char const* shopRope_001 = "shopRope_001.png";
	constexpr char const* star_small01_001 = "star_small01_001.png";
	constexpr char const* storeItemIcon_001 = "storeItemIcon_001.png";
	constexpr char const* top_tab_off_001 = "top_tab_off_001.png";
	constexpr char const* top_tab_on_001 = "top_tab_on_001.png";
	constexpr char const* treasureRoomLabel_001 = "treasureRoomLabel_001.png";
	constexpr char const* uiDot_001 = "uiDot_001.png";
	constexpr char const* usercoin_small01_001 = "usercoin_small01_001.png";
	constexpr char const* weeklyLevelLabel_001 = "weeklyLevelLabel_001.png";
}
