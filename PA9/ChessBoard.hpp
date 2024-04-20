#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Pieces.hpp"
#include "Point.hpp"
#include <ctime>
#include <cstdlib>

//This file is used to define and draw the chess board.

class Board{

private:
    void move(Piece* piece, Point p);     // executes a move

public:

    Piece* boardPieces[8][8];

    Board();

    void drawBoardState(sf::RenderWindow& window);

    Point findLocation(int inputX, int inputY);
};