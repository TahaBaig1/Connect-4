#ifndef GAME_H
#define GAME_H

#include <SFML/Audio.hpp>
#include "Board.h"

enum Status {
	CONTINUE,TIE,WIN
};

enum Mode {
	PLAYER_V_PLAYER, AI_FIRST, AI_SECOND
};

//contains game loop and all game components/logic
class Game {
	public:
		Game(sf::RenderWindow& window, int numConnected_ = 4, int turn_ = 1); //default connect 4 pieces game
		void run(); //game loop
	private:
		int turn; //current turn number
		int numConnected; //number of pieces required to be connected in a line in order to win
		sf::RenderWindow& window;
		Board board;
		sf::CircleShape marker;

		//for sound that plays when piece is dropped on board
		sf::SoundBuffer buffer;
		sf::Sound dropSound;

		Mode displayTitleScreen() const;
		sf::Color getCurrentColor() const;
		Status isGameOver(Position& placed) const;
		int convertMousePosToColumn(sf::Vector2i& pos) const;
		void drawMarker(int col);
		void animateDrop(Position& placed);
		bool endLoop(Status gameStatus);
		void setText(sf::Text& text, sf::Font& font, sf::Color& color, int charSize) const;
		void drawEndText(Status gameStatus);
		void reset();
};

#endif