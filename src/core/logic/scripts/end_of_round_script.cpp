//
// Created by Viktor on 24.1.2021 г..
//

#include <iostream>
#include "include/end_of_round_script.h"
#include "../../include/game_utils.h"
#include "../../../lib/include/lib.h"
#include "../../graphics/screens/include/hud_renderer.h"
#include "../events/include/start_round.h"
#include "../events/include/reinitialize.h"


EndOfRoundScript::EndOfRoundScript(Gamelib& game) : game(game){

	sortDucksUI();
	scoreCounter = (float) game.dataSystem->currentGameData.score;
	if(type == PERFECT) {
		game.dataSystem->currentGameData.score += 10000;
	}
	// We have EndOfRoundType : 0 -> Perfect, 1 -> Nothing, 2 -> GameOver
	// We have MusicType      : 2 -> Perfect, 3 -> RoundClear, 3 -> GameOver
	game.audioSystem->playMusic(static_cast<MusicType>(type + 2));

	game.graphicsSystem->getHudRenderer().endOfRoundWindow.update(type);
}

void EndOfRoundScript::sortDucksUI() {
	int pos = 0;
	for (int i = 0; i < 10; i++) {
		if (game.dataSystem->currentGameData.ducksTracker[i] == KILLED) {
			duckTracker[pos] = KILLED;
			pos++;
		}
	}
	// because we start from 0 to 9, now we are between 1 and 10
	if(game.dataSystem->currentGameData.minimumDucksToAdvance <= pos){
		// if the last changed position was the last position in duckTracker
		// then we have perfect score, else nothing
		type = pos == 10 ? PERFECT : NOTHING;
	}
	else{
		type = GAME_OVER;
		// saving the user's high score
		if(game.dataSystem->userData.isBetterHighScore(game.dataSystem->currentGameData.score)) {
			game.dataSystem->userData.setHighScore(game.dataSystem->currentGameData.score);
			game.dataSystem->userData.save();
			// update the menu label
			Label& highScoreLabel = ((MenuScreen*) game.graphicsSystem->getScreen(Menu))->maximumScore;
			highScoreLabel.setText("TOP SCORE = " + std::to_string(game.dataSystem->userData.getHighScore()));
			highScoreLabel.updateText();
		}
	}
}

bool EndOfRoundScript::update(Gamelib& game) {
	// we want all the scripts to have finished
	// and this to be the only one
	if (game.logicSystem->getScriptsSize() != 1) return false;
	currentTime += Lib::graphics->getDeltaTime();
	if (currentTime > WAIT_TIME) {
		if (type == PERFECT) {
			animateScoreGain();
			if(!isAnimationComplete()) return false;
		}
		if (currentTime > WAIT_TIME * 3) {
			game.graphicsSystem->getHudRenderer().endOfRoundWindow.setVisible(false);
			if(type == GAME_OVER){
				game.gameStateManager->changeState(Menu);
				game.graphicsSystem->start(Menu);
				game.logicSystem->post(new Reinitialize());

			}
			else {
				game.logicSystem->post(new StartRound());
			}
			return true;
		}
	} else {
		blinkDucksUI();
	}

	return false;
}

void EndOfRoundScript::blinkDucksUI() {
	if (blinked) {
		// we skip just 1 frame each next frame
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

void EndOfRoundScript::animateScoreGain() {
	static const float SCORE_PER_SECOND = 5000.0f;
	scoreCounter = std::min((int) (scoreCounter + SCORE_PER_SECOND * Lib::graphics->getDeltaTime()),
	                        game.dataSystem->currentGameData.score);
	displayNewScore();

}

void EndOfRoundScript::displayNewScore() const {
	int zeros = 0;
	int score = (int) scoreCounter;
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

bool EndOfRoundScript::isAnimationComplete() const {
	return (int) scoreCounter == game.dataSystem->currentGameData.score;
}



