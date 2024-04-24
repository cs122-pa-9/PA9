#include "ChessBoard.hpp"

// sets up the board with random pieces except for kings

Board::Board() {

	srand(time(NULL));

	// initialize the kings in a set location
	this->boardPieces[0][3] = new King('b', 'K', 0, 3);
	this->boardPieces[7][4] = new King('w', 'k', 7, 4);

	// loops to initalize the board with random pieces for black
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 8; j++) {

			if (!(i == 0 && j == 3)) {
				int randNum = rand() % 5;

				switch (randNum) {
				case 0:
					this->boardPieces[i][j] = new Pawn('b', 'P', i, j);
					break;
				case 1:
					this->boardPieces[i][j] = new Knight('b', 'N', i, j);
					break;
				case 2:
					this->boardPieces[i][j] = new Queen('b', 'Q', i, j);
					break;
				case 3:
					this->boardPieces[i][j] = new Rook('b', 'R', i, j);
					break;
				case 4:
					this->boardPieces[i][j] = new Bishop('b', 'B', i, j);
					break;
				}
			}
		}
	}

	// loops to set unoccupied spaces on the board to null
	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			this->boardPieces[i][j] = nullptr;
		}
	}

	// loops to initalize the board with random pieces for black
	for (int i = 6; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			if (!(i == 7 && j == 4)) {
				int randNum = rand() % 5;

				switch (randNum) {
				case 0:
					this->boardPieces[i][j] = new Pawn('w', 'P', i, j);
					break;
				case 1:
					this->boardPieces[i][j] = new Knight('w', 'N', i, j);
					break;
				case 2:
					this->boardPieces[i][j] = new Queen('w', 'Q', i, j);
					break;
				case 3:
					this->boardPieces[i][j] = new Rook('w', 'R', i, j);
					break;
				case 4:
					this->boardPieces[i][j] = new Bishop('w', 'B', i, j);
					break;
				}
			}
		}
	}
}

//drawBoardState takes a 2d array which represents the current state of the chess board and displays it on the board
void Board::drawBoardState(sf::RenderWindow& window) {
	sf::Texture boardTexture;
	boardTexture.loadFromFile("chessboard.jpg");
	sf::Sprite chessBoardImage(boardTexture);

	window.draw(chessBoardImage);

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

