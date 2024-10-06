#include "Game.hpp"
#include <windows.h>

Game::Game(sf::RenderWindow& w, sf::Event& e) : window(w), event(e) {

}

// runs a turn
// run turn function written by me (Ziang)
void Game::runTurn() {

	while (window.waitEvent(this->event))
	{
		if (this->event.type == sf::Event::MouseButtonReleased && !pieceSelected) {			// if mouse is clicked and there isn't a piece yet selected
			int x = this->event.mouseButton.x;
			int y = this->event.mouseButton.y;
			std::cout << x << ", " << y << "\n";\
			b = this->board.findLocation(x, y);
			
			// set pieceSelected to true if piece clicked is the same color as current turn
			if (board.boardPieces[b.getX()][b.getY()] != nullptr && this->turn == board.boardPieces[b.getX()][b.getY()]->getColor()) {		
				pieceSelected = true;
			}

			std::cout << b.getX() << ", " << b.getY() << "\n";
			continue;
		}


		if (this->event.type == sf::Event::MouseButtonReleased && pieceSelected) {			// if mouse is clicked and there is a piece selected
			Point p(this->event.mouseButton.y/100, this->event.mouseButton.x/100);

			if (board.boardPieces[b.getX()][b.getY()]->validMove(p, this->board.boardPieces)) {			// check if move can be executed and execute turn
				this->board.move(board.boardPieces[b.getX()][b.getY()], p);
				this->turnFinished = true;
			}
			this->pieceSelected = false;		// if invalid move, set piece selected back to false
		}

		if (turnFinished) {
			break;
		}
	}
}


bool Game::isCheck(char checkThisColor, Piece* boardArr[8][8]) {
	char opponentColor;
	if (checkThisColor == 'w') {
		opponentColor = 'b';
	}
	else if (checkThisColor == 'b') {
		opponentColor = 'w';
	}

	//find king
	Point kingPos;
	for (int x = 0; x < 8; ++x) {
		for (int y = 0; y < 8; ++y) { //iterate through entire board
			Piece* kingPiece = boardArr[x][y];
			//assuming we are using 'K' to represent the King:
			if (kingPiece != nullptr && kingPiece->getPiece() == 'K' && kingPiece->getColor() == checkThisColor) {
				kingPos = kingPiece->getLocation();
				break;
			}
		}
	}
	//check every opponent piece to see if it is putting the king in check 
	for (int x = 0; x < 8; ++x) {
		for (int y = 0; y < 8; ++y) {
			Piece* targetPiece = boardArr[x][y];
			if (targetPiece != nullptr && targetPiece->getColor() == opponentColor) {
				Point targetPos = targetPiece->getLocation();
				if (targetPiece->validMove(kingPos, boardArr)) {
					return true; //king is in check
				}
			}
		}
	}

	return false; //king is not in check
}


// functions for checking check and checkmate don't work

bool Game::isCheckmate(char checkThisColor, Piece* boardArr[8][8]) {
	char opponentColor;
	if (checkThisColor == 'w') {
		opponentColor = 'b';
	}
	else if (checkThisColor == 'b') {
		opponentColor = 'w';
	}

	Point kingPos;
	for (int x = 0; x < 8; ++x) {
		for (int y = 0; y < 8; ++y) {
			Piece* kingPiece = boardArr[x][y];
			if (kingPiece != nullptr && kingPiece->getPiece() == 'K' && kingPiece->getColor() == checkThisColor) {
				kingPos = kingPiece->getLocation();
				break;
			}
		}
	}

	if (!isCheck(checkThisColor, boardArr)) {
		return false; //king is not in check so it cannot be checkmate
	}

	//check if king can escape check
	for (int x = -1; x <= 1; ++x) {
		for (int y = -1; y <= 1; ++y) {
			//move to each possible space through the loop
			int newX = kingPos.getX() + x;
			int newY = kingPos.getY() + y;

			if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
				//check if there is a piece in the new position
				if (boardArr[newX][newY] == nullptr || boardArr[newX][newY]->getColor() != checkThisColor) {
					//if not then move king to the new position
					boardArr[kingPos.getX()][kingPos.getY()]->setLocation(newX, newY);

					//check if the king is still in check after moving
					if (!isCheck(checkThisColor, boardArr)) {
						//reset the board
						boardArr[kingPos.getX()][kingPos.getY()]->setLocation(kingPos.getX(), kingPos.getY()); //reset king location
						return false;
					}

					//reset the board for next iteration
					boardArr[kingPos.getX()][kingPos.getY()]->setLocation(kingPos.getX(), kingPos.getY());
				}
			}
		}
	}

	return true;
}



// rungame function written by me (ziang)
void Game::runGame() {

	this->board.drawBoardState(this->window);
	window.display();

	while (true) {

		this->turnFinished = false;
		runTurn();
	
		this->board.drawBoardState(this->window);
		window.display();

		if (isCheckmate(this->turn, this->board.boardPieces)) {
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
