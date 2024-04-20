#include "Pieces.hpp"

// constructors
Piece::Piece() {
	this->piece = ',';
	this->color = 'n';
}

Piece::Piece(char c, char col) {
	this->piece = c;
	this->color = col;
}

Piece::Piece(char c, char col, int x, int y) {
	this->piece = c;
	this->color = col;
	this->location = Point(x, y);
}

Piece::~Piece() {};

// what happens when the piece is clicked
bool Piece::actionOnClick(sf::Event event, Piece* boardArr[8][8]) {

	Point moves[30];
	int options = findMoves(moves, boardArr);

	if (event.type == sf::Event::MouseButtonReleased) {
		int mouseY = event.mouseButton.x / 100;
		int mouseX = event.mouseButton.y / 100;
		for (int i = 0; i < options; i++) {
			if (moves[i].getX() == mouseX && moves[i].getY() == mouseY) {
				return true;
			}
		}
	}

	return false;
}

// getters
char Piece::getPiece() {
	return this->piece;
}

char Piece::getColor() {
	return this->color;
}

Point Piece::getLocation() {
	return this->location;
}

// setters
void Piece::setPiece(char c) {
	this->piece = c;
}

void Piece::setColor(char col) {
	this->color = col;
}

void Piece::setLocation(int x, int y) {
	this->location = Point(x, y);
}







King::King(char col, char c, int x, int y) {
	this->setColor(col);
	this->setPiece(c);
	this->setLocation(x, y);

	if (this->getColor() == 'b') {
		this->Texture.loadFromFile("bking.png");
	}
	else {
		this->Texture.loadFromFile("wking.png");
	}

	this->Sprite.setTexture(this->Texture);
}

int King::findMoves(Point(&arr)[30], Piece* boardArr[8][8]) {
	return 0;
}



Queen::Queen(char col, char c, int x, int y) {
	this->setColor(col);
	this->setPiece(c);
	this->setLocation(x, y);

	if (this->getColor() == 'b') {
		this->Texture.loadFromFile("bqueen.png");
	}
	else {
		this->Texture.loadFromFile("wqueen.png");
	}

	this->Sprite.setTexture(this->Texture);
}

int Queen::findMoves(Point(&arr)[30], Piece* boardArr[8][8]) {
	return 0;
}



Bishop::Bishop(char col, char c, int x, int y) {
	this->setColor(col);
	this->setPiece(c);
	this->setLocation(x, y);

	if (this->getColor() == 'b') {
		this->Texture.loadFromFile("bbishop.png");
	}
	else {
		this->Texture.loadFromFile("wbishop.png");
	}

	this->Sprite.setTexture(this->Texture);
}

int Bishop::findMoves(Point(&arr)[30], Piece* boardArr[8][8]) {
	return 0;
}



Rook::Rook(char col, char c, int x, int y) {
	this->setColor(col);
	this->setPiece(c);
	this->setLocation(x, y);

	if (this->getColor() == 'b') {
		this->Texture.loadFromFile("brook.png");
	}
	else {
		this->Texture.loadFromFile("wrook.png");
	}

	this->Sprite.setTexture(this->Texture);
}

int Rook::findMoves(Point(&arr)[30], Piece* boardArr[8][8]) {
	return 0;
}



Knight::Knight(char col, char c, int x, int y) {
	this->setColor(col);
	this->setPiece(c);
	this->setLocation(x, y);

	if (this->getColor() == 'b') {
		this->Texture.loadFromFile("bknight.png");
	}
	else {
		this->Texture.loadFromFile("wknight.png");
	}

	this->Sprite.setTexture(this->Texture);
}

int Knight::findMoves(Point(&arr)[30], Piece* boardArr[8][8]) {
	return 0;
}



Pawn::Pawn(char col, char c, int x, int y) {
	this->setColor(col);
	this->setPiece(c);
	this->setLocation(x, y);

	if (this->getColor() == 'b') {
		this->Texture.loadFromFile("bpawn.png");
	}
	else {
		this->Texture.loadFromFile("wpawn.png");
	}

	this->Sprite.setTexture(this->Texture);
}

int Pawn::findMoves(Point(&arr)[30], Piece* boardArr[8][8]) {
	if (isFirstMove) {
		return 0;
	}
	return 0;
}