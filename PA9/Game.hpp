#include "ChessBoard.hpp"

class Game{
private:
	char turn = 'w';

	sf::Event& event;
	sf::RenderWindow& window;

	Point b;
	bool pieceSelected = false;
	bool turnFinished = false;

	Board board;

	void runTurn();

	bool isCheck(char checkThisColor, Piece* boardArr[8][8]);

	bool isCheckmate(char checkThisColor, Piece* boardArr[8][8]);

public:

	Game(sf::RenderWindow& w, sf::Event& e);

	void runGame();

};