#include <Geode/modify/PlayLayer.hpp>

class $(PlayLayer) {
	void updateProgressbar() {
		PlayLayer::updateProgressbar();

		double percent = (m_player1->getPositionX() / m_levelLength) * 100;
		char str[64];
		sprintf(str, "%.2lf%%", percent);
		this->m_percentLabel->setString(str);
	}
};
