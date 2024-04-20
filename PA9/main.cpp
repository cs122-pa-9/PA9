#include "ChessBoard.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "chess 2 electric boogaloo");
    sf::Texture boardTexture;
    boardTexture.loadFromFile("chessboard.jpg");
    sf::Sprite chessBoardImage(boardTexture);

    Board board;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::MouseButtonReleased) {
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;
                std::cout << x << ", " << y << "\n";
                Point b = board.findLocation(x, y);
                std::cout << b.getX() << ", " << b.getY() << "\n";
            }

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(chessBoardImage);
        board.drawBoardState(window);
        window.display();
    }

    return 0;
}