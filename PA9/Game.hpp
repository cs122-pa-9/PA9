#include "ChessBoard.hpp"

class Game{
private:
	char turn = 'w';

	sf::Event& event;
	sf::RenderWindow& window;

	Board board;

	void runTurn();

	bool isCheck();

	bool isCheckmate();

public:

	Game(sf::RenderWindow& w, sf::Event& e);

	void runGame();

};