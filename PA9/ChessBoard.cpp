#include "ChessBoard.hpp"


// sets up the board
Board::Board() {
	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			this->boardPieces[i][j] = nullptr;
		}
	}
}

//drawBoardState takes a 2d array which represents the current state of the chess board and displays it on the board
void Board::drawBoardState(sf::RenderWindow window) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (this->boardPieces[i][j] != nullptr) {
				boardPieces[i][j]->Sprite.setPosition(j*100.f, i*100.f);
				window.draw(boardPieces[i][j]->Sprite);
			}
		}
	}
}

Point Board::findLocation(int inputX, int inputY) {
	Point indexPoint(inputY / 100, inputX / 100);
	return indexPoint;
}

void Board::move(Piece* piece, Point p) {
	boardPieces[p.getX()][p.getY()] = piece;
	boardPieces[piece->getLocation().getX()][piece->getLocation().getY()] = nullptr;
	piece->setLocation(p.getX(), p.getY());
}

