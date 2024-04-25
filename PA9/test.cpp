#include "test.hpp"

void TestFunctions::testQueenMoves() {
    Piece* boardPieces[8][8] = { nullptr };
    Point arr[30];
    int count = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            delete boardPieces[i][j];
            boardPieces[i][j] = nullptr;
        }
    }

    boardPieces[2][4] = new Queen('w', 'Q', 2, 4);
    count = boardPieces[2][4]->findMoves(arr, boardPieces);

    std::cout << "Queens are available at coordinates (2,4) that can be moved to:" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << "(" << arr[i].getX() << ", " << arr[i].getY() << ")" << std::endl;
    }
}

void TestFunctions::testKnightMoves() {
    Piece* boardPieces[8][8] = { nullptr };
    Point arr[30];
    int count = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            delete boardPieces[i][j];
            boardPieces[i][j] = nullptr;
        }
    }

    boardPieces[2][4] = new Knight('w', 'N', 2, 4);
    count = boardPieces[2][4]->findMoves(arr, boardPieces);

    std::cout << "Kight are available at coordinates (2,4) that can be moved to:" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << "(" << arr[i].getX() << ", " << arr[i].getY() << ")" << std::endl;
    }
}

bool TestFunctions::testFindLocation(int mouseX, int mouseY, Point expectedResult) {
    Board testBoard;
    Point result = testBoard.findLocation(mouseX, mouseY);
    if (result == expectedResult) {
        std::cout << "Test passed" << std::endl;
        return true;
    }
    else {
        std::cout << "Test failed" << std::endl;
        return false;
    }
}

void TestFunctions::testKingMoves() {
    Piece* boardPieces[8][8] = { nullptr };
    Point arr[30];
    int count = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            delete boardPieces[i][j];
            boardPieces[i][j] = nullptr;
        }
    }

    boardPieces[2][4] = new King('w', 'K', 2, 4);
    count = boardPieces[2][4]->findMoves(arr, boardPieces);

    std::cout << "King are available at coordinates (2,4) that can be moved to:" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << "(" << arr[i].getX() << ", " << arr[i].getY() << ")" << std::endl;
    }
}

void TestFunctions::testRookMoves() {
    Piece* boardPieces[8][8] = { nullptr };
    Point arr[30];
    int count = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            delete boardPieces[i][j];
            boardPieces[i][j] = nullptr;
        }
    }

    boardPieces[2][4] = new Rook('w', 'R', 2, 4);
    count = boardPieces[2][4]->findMoves(arr, boardPieces);

    std::cout << "Rook are available at coordinates (2,4) that can be moved to:" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << "(" << arr[i].getX() << ", " << arr[i].getY() << ")" << std::endl;
    }
}