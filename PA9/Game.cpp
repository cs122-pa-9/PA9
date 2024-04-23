#include "Game.hpp"
#include <windows.h>

Game::Game(sf::RenderWindow& w, sf::Event& e) : window(w), event(e) {

}

void Game::runTurn() {
	Point b;
	bool pieceSelected = false;

	while (window.pollEvent(this->event))
	{
		if (this->event.type == sf::Event::MouseButtonReleased && !pieceSelected) {
			int x = this->event.mouseButton.x;
			int y = this->event.mouseButton.y;
			std::cout << x << ", " << y << "\n";\
			b = this->board.findLocation(x, y);
			
			if (board.boardPieces[b.getX()][b.getY()] != nullptr && this->turn == board.boardPieces[b.getX()][b.getY()]->getColor()) {
				pieceSelected = true;
			}

			std::cout << b.getX() << ", " << b.getY() << "\n";
			std::cout << b.getX() << ", " << b.getY() << "\n";
		}

		if (this->event.type == sf::Event::MouseButtonReleased && pieceSelected) {
			Point p(this->event.mouseButton.y/100, this->event.mouseButton.x/100);

			if (board.boardPieces[b.getX()][b.getY()]->validMove(p, this->board.boardPieces)) {
				this->board.move(board.boardPieces[b.getX()][b.getY()], p);
				break;
			}
			else {
				pieceSelected = false;
			}
		}
	}
}

bool isCheck();

bool Game::isCheckmate() {
	return false;
}

void Game::runGame() {

	this->board.drawBoardState(this->window);

	window.display();

	while (true) {

		runTurn();
	
		this->board.drawBoardState(this->window);

		if (isCheckmate()) {
			if (this->turn == 'w') {
				std::cout << "white wins";
			}
			else {
				std::cout << "black wins";
			}
		}

		if (this->turn == 'w') {
			this->turn = 'b';
		}
		else {
			this->turn = 'w';
		}
	}
}