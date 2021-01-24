//
// Created by Viktor on 24.1.2021 г..
//

#include "include/end_of_round_script.h"
#include "../../include/game_utils.h"
#include "../../../lib/include/lib.h"
#include "../../graphics/screens/include/hud_renderer.h"
#include "../events/include/start_round.h"


EndOfRoundScript::EndOfRoundScript(Gamelib& game) {
	sortDucksUI(game);
	scoreCounter = (float) game.dataSystem->currentGameData.score;

}

void EndOfRoundScript::sortDucksUI(Gamelib& game) {
	int pos = 0;
	for (int i = 0; i < 10; i++) {
		if (game.dataSystem->currentGameData.ducksTracker[i] == KILLED) {
			duckTracker[pos] = KILLED;
			pos = i + 1;
		}
	}
	ducksAlive = 10 - pos;
}

bool EndOfRoundScript::update(Gamelib& game) {
	// we want all the scripts to have finished
	// and this to be the only one
	if (game.logicSystem->getScriptsSize() != 1) return false;
	currentTime += Lib::graphics->getDeltaTime();
	if (currentTime > WAIT_TIME) {
		EndOfRoundType type = ducksAlive == 0 ? PERFECT : NOTHING;
		game.graphicsSystem->getHudRenderer().endOfRoundWindow.update(type);
		if (type == PERFECT) {
			animateScoreGain(game);
		}
		if (currentTime > WAIT_TIME * 3) {
			game.logicSystem->post(new StartRound());
			return true;
		}
	} else {
		blinkDucksUI(game);
	}

	return false;
}

void EndOfRoundScript::blinkDucksUI(Gamelib& game) {
	if (blinked) {
		blinked = false;
		return;
	}
	if (game.dataSystem->currentGameData.ducksTracker[0] == KILLED) {
		for (auto& i : game.dataSystem->currentGameData.ducksTracker) {
			i = ESCAPED;
		}
	} else {
		for (int i = 0; i < 10; i++) {
			game.dataSystem->currentGameData.ducksTracker[i] = duckTracker[i];
		}
	}
	blinked = true;
}

void EndOfRoundScript::animateScoreGain(Gamelib& game) {
	static float SCORE_PER_SECOND = 1000.0f;
	scoreCounter = std::min((int) (scoreCounter + SCORE_PER_SECOND * Lib::graphics->getDeltaTime()),
	                        game.dataSystem->currentGameData.score);
	displayNewScore(game);

}

void EndOfRoundScript::displayNewScore(Gamelib& game) const {
	int zeros = 0;
	int score = scoreCounter;
	while(score){
		score /= 10;
		zeros++;
	}
	std::string displayScore;
	for(int i = 0; i < 6 - zeros; i++){
		displayScore += "0";
	}
	game.graphicsSystem->getHudRenderer().scoreLabel.setText(displayScore + std::to_string((int) scoreCounter));
	game.graphicsSystem->getHudRenderer().scoreLabel.updateText();
}



