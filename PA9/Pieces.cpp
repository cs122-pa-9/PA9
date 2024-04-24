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

// checks if a given move is valid
bool Piece::validMove(Point p, Piece* boardArr[8][8]) {

	// array for possible moves
	Point moves[30];
	int options = findMoves(moves, boardArr);

	int mouseY = p.getY();
	int mouseX = p.getX();
	for (int i = 0; i < options; i++) {
		if (moves[i].getX() == mouseX && moves[i].getY() == mouseY) {
			return true;
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

	int x = getLocation().getX();
	int y = getLocation().getY();

	static const int moves[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
	int count = 0;

	for (int i = 0; i < 8; ++i) {
		int new_x = x + moves[i][0];
		int new_y = y + moves[i][1];

		if (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8) { // Check bounds
			Piece* target = boardArr[new_x][new_y];
			if (!target || target->getColor() != this->getColor()) { // Spot is empty or contains an opponent
				arr[count++] = { new_x, new_y }; // Store the move
			}
		}
	}
	return count;
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
	int numPossibleMoves = 0;
	int x = getLocation().getX(); //get coords of bishop
	int y = getLocation().getY();

	for (int i = 1; i < 8; i++) { //check diagonally top left
		int checkX = x - i;
		int checkY = y - i;

		//check if in bounds of board
		if (checkX < 0 || checkX >= 8 || checkY < 0 || checkY >= 8) {
			break;
		}
		if (boardArr[checkX][checkY] == nullptr) { //check if there is no piece
			arr[numPossibleMoves++] = Point(checkX, checkY);
		}
		//check if there is an enemy piece
		else if (boardArr[checkX][checkY]->getColor() != this->getColor()) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
			break;
		}
		else { //there must be a friendly piece
			break;
		}
	}
	for (int i = 1; i < 8; i++) { //check diagonally top right
		int checkX = x - i;
		int checkY = y + i;
		if (checkX < 0 || checkX >= 8 || checkY < 0 || checkY >= 8) {
			break;
		}
		if (boardArr[checkX][checkY] == nullptr) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
		}
		else if (boardArr[checkX][checkY]->getColor() != this->getColor()) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
			break;
		}
		else {
			break;
		}
	}
	for (int i = 1; i < 8; i++) { //check diagonally bottom left
		int checkX = x + i;
		int checkY = y - i;
		if (checkX < 0 || checkX >= 8 || checkY < 0 || checkY >= 8) {
			break;
		}
		if (boardArr[checkX][checkY] == nullptr) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
		}
		else if (boardArr[checkX][checkY]->getColor() != this->getColor()) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
			break;
		}
		else {
			break;
		}
	}
	for (int i = 1; i < 8; i++) { //check diagonally bottom right
		int checkX = x + i;
		int checkY = y + i;
		if (checkX < 0 || checkX >= 8 || checkY < 0 || checkY >= 8) {
			break;
		}
		if (boardArr[checkX][checkY] == nullptr) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
		}
		else if (boardArr[checkX][checkY]->getColor() != this->getColor()) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
			break;
		}
		else {
			break;
		}
	}

	return numPossibleMoves;
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
	int numPossibleMoves = 0;
	int x = getLocation().getX(); //get coords of rook
	int y = getLocation().getY();

	for (int i = 1; i < 8; i++) { //check up
		int checkX = x - i;
		int checkY = y;

		//check if in bounds of board
		if (checkX < 0 || checkX >= 8 || checkY < 0 || checkY >= 8) {
			break;
		}
		if (boardArr[checkX][checkY] == nullptr) { //check if there is no piece
			arr[numPossibleMoves++] = Point(checkX, checkY);
		}
		//check if there is an enemy piece
		else if (boardArr[checkX][checkY]->getColor() != this->getColor()) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
			break;
		}
		else { //there must be a friendly piece
			break;
		}
	}
	for (int i = 1; i < 8; i++) { //check right
		int checkX = x;
		int checkY = y + i;
		if (checkX < 0 || checkX >= 8 || checkY < 0 || checkY >= 8) {
			break;
		}
		if (boardArr[checkX][checkY] == nullptr) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
		}
		else if (boardArr[checkX][checkY]->getColor() != this->getColor()) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
			break;
		}
		else {
			break;
		}
	}
	for (int i = 1; i < 8; i++) { //check left
		int checkX = x;
		int checkY = y - i;
		if (checkX < 0 || checkX >= 8 || checkY < 0 || checkY >= 8) {
			break;
		}
		if (boardArr[checkX][checkY] == nullptr) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
		}
		else if (boardArr[checkX][checkY]->getColor() != this->getColor()) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
			break;
		}
		else {
			break;
		}
	}
	for (int i = 1; i < 8; i++) { //check down
		int checkX = x + i;
		int checkY = y;
		if (checkX < 0 || checkX >= 8 || checkY < 0 || checkY >= 8) {
			break;
		}
		if (boardArr[checkX][checkY] == nullptr) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
		}
		else if (boardArr[checkX][checkY]->getColor() != this->getColor()) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
			break;
		}
		else {
			break;
		}
	}

	return numPossibleMoves;
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

	int numPossibleMoves = 0;
	int x = getLocation().getX(); //get coords of rook
	int y = getLocation().getY();

	for (int i = 1; i < 8; i++) { //check up
		int checkX = x - i;
		int checkY = y;

		//check if in bounds of board
		if (checkX < 0 || checkX >= 8 || checkY < 0 || checkY >= 8) {
			break;
		}
		if (boardArr[checkX][checkY] == nullptr) { //check if there is no piece
			arr[numPossibleMoves++] = Point(checkX, checkY);
		}
		//check if there is an enemy piece
		else if (boardArr[checkX][checkY]->getColor() != this->getColor()) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
			break;
		}
		else { //there must be a friendly piece
			break;
		}
	}
	for (int i = 1; i < 8; i++) { //check right
		int checkX = x;
		int checkY = y + i;
		if (checkX < 0 || checkX >= 8 || checkY < 0 || checkY >= 8) {
			break;
		}
		if (boardArr[checkX][checkY] == nullptr) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
		}
		else if (boardArr[checkX][checkY]->getColor() != this->getColor()) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
			break;
		}
		else {
			break;
		}
	}
	for (int i = 1; i < 8; i++) { //check left
		int checkX = x;
		int checkY = y - i;
		if (checkX < 0 || checkX >= 8 || checkY < 0 || checkY >= 8) {
			break;
		}
		if (boardArr[checkX][checkY] == nullptr) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
		}
		else if (boardArr[checkX][checkY]->getColor() != this->getColor()) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
			break;
		}
		else {
			break;
		}
	}
	for (int i = 1; i < 8; i++) { //check down
		int checkX = x + i;
		int checkY = y;
		if (checkX < 0 || checkX >= 8 || checkY < 0 || checkY >= 8) {
			break;
		}
		if (boardArr[checkX][checkY] == nullptr) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
		}
		else if (boardArr[checkX][checkY]->getColor() != this->getColor()) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
			break;
		}
		else {
			break;
		}
	}

	for (int i = 1; i < 8; i++) { //check diagonally top left
		int checkX = x - i;
		int checkY = y - i;

		//check if in bounds of board
		if (checkX < 0 || checkX >= 8 || checkY < 0 || checkY >= 8) {
			break;
		}
		if (boardArr[checkX][checkY] == nullptr) { //check if there is no piece
			arr[numPossibleMoves++] = Point(checkX, checkY);
		}
		//check if there is an enemy piece
		else if (boardArr[checkX][checkY]->getColor() != this->getColor()) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
			break;
		}
		else { //there must be a friendly piece
			break;
		}
	}
	for (int i = 1; i < 8; i++) { //check diagonally top right
		int checkX = x - i;
		int checkY = y + i;
		if (checkX < 0 || checkX >= 8 || checkY < 0 || checkY >= 8) {
			break;
		}
		if (boardArr[checkX][checkY] == nullptr) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
		}
		else if (boardArr[checkX][checkY]->getColor() != this->getColor()) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
			break;
		}
		else {
			break;
		}
	}
	for (int i = 1; i < 8; i++) { //check diagonally bottom left
		int checkX = x + i;
		int checkY = y - i;
		if (checkX < 0 || checkX >= 8 || checkY < 0 || checkY >= 8) {
			break;
		}
		if (boardArr[checkX][checkY] == nullptr) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
		}
		else if (boardArr[checkX][checkY]->getColor() != this->getColor()) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
			break;
		}
		else {
			break;
		}
	}
	for (int i = 1; i < 8; i++) { //check diagonally bottom right
		int checkX = x + i;
		int checkY = y + i;
		if (checkX < 0 || checkX >= 8 || checkY < 0 || checkY >= 8) {
			break;
		}
		if (boardArr[checkX][checkY] == nullptr) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
		}
		else if (boardArr[checkX][checkY]->getColor() != this->getColor()) {
			arr[numPossibleMoves++] = Point(checkX, checkY);
			break;
		}
		else {
			break;
		}
	}

	return numPossibleMoves;
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
	int count = 0;
	int x = getLocation().getX();
	int y = getLocation().getY();
	const char cColor = boardArr[x][y]->getColor();
	int moves[8][2] = { {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1} };

	for (int i = 0; i < 8; ++i) {
		int direction_x = moves[i][0];
		int direction_y = moves[i][1];
		int new_x = getLocation().getX() + direction_x;
		int new_y = getLocation().getY() + direction_y;

		if (new_x >= 0 && new_x < 8 && new_y >= 0 && y < 8) {
			if (boardArr[new_x][new_y]->getPiece() == 0 || boardArr[new_x][new_y]->getPiece() != cColor) {
				arr[count++] = Point(new_x, new_y);
			}
		}
	}
	return count;
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

	return 0;
}