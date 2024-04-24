#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Point.hpp"


class Piece {

private:
	char piece;
	Point location;
	char color;

public:

	sf::Texture Texture;
	sf::Sprite Sprite;

	Piece();

	Piece(char c, char col);

	Piece(char c, char col, int x, int y);

	~Piece();

	bool validMove(Point p, Piece* boardArr[8][8]);      // checks if action can happen when piece is clicked 

	virtual int findMoves(Point(&arr)[30], Piece* boardArr[8][8]) = 0;     // finds the list of points where the piece can move to

	char getPiece();
	char getColor();
	Point getLocation();

	void setPiece(char c);
	void setColor(char col);
	void setLocation(int x, int y);

};



// the king piece
class King : public Piece {

public:
	King(char col, char c, int x, int y);


	int findMoves(Point(&arr)[30], Piece* boardArr[8][8]);
};



// the bishop piece
class Bishop : public Piece {

public:
	Bishop(char col, char c, int x, int y);

	int findMoves(Point(&arr)[30], Piece* boardArr[8][8]);
};


// the rook piece
class Rook : public Piece {

public:
	Rook(char col, char c, int x, int y);

	int findMoves(Point(&arr)[30], Piece* boardArr[8][8]);
};



// the queen piece
class Queen : public Piece{

public:
	Queen(char col, char c, int x, int y);

	int findMoves(Point(&arr)[30], Piece* boardArr[8][8]);
};



// the knight piece
class Knight : public Piece {

public:
	Knight(char col, char c, int x, int y);

	int findMoves(Point(&arr)[30], Piece* boardArr[8][8]);
};



// the pawn piece
class Pawn : public Piece {

public:
	Pawn(char col, char c, int x, int y);

	int findMoves(Point(&arr)[30], Piece* boardArr[8][8]);
};
