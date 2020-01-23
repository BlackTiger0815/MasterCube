#include <stdexcept>
#include <sstream>
#include "mastermindcube.h"

MastermindCube::~MastermindCube() = default;

MastermindCube::MastermindCube(){
    filler = std::string((int) cube[0][0][0].toString().length() * 3 + 2, ' ');
}

void MastermindCube::print() {
    printSide(0);
    for (int j = 0; j < MAX_ROW_INDEX; j++) {
        for (int i = 1; i < 5; i++) {
            printRow(i, j);
            std::cout << "  ";
        }
        std::cout << std::endl << std::endl;
    }
    printSide(5);
}

void MastermindCube::printRow(int i, int j) {
    for (int k = 0; k < MAX_COL_INDEX; k++) {
        std::cout << cube[i][j][k].toString();
    }
}

void MastermindCube::printSide(int i) {
    std::cout << std::endl;
    for (int j = 0; j < MAX_ROW_INDEX; j++) {
        std::cout << filler;
        printRow(i, j);
        std::cout << std::endl << std::endl;
    }
    std::cout << std::endl;
}

void MastermindCube::setCubie(int side, int row, int col, int color) { //, float probability) {
    if ((side < 0 || side >= MAX_SIDE_INDEX)) {
        throw std::invalid_argument("Invalid side number" );
    }
    if ((row < 0 || row >= MAX_ROW_INDEX)) {
        throw std::invalid_argument("Invalid row number" );
    }
    if ((col < 0 || col >= MAX_COL_INDEX)) {
        throw std::invalid_argument("Invalid column number" );
    }
    cube[side][row][col].setColor(color);

    //cube[side][row][col].setProbability(probability);
}

/* void MastermindCube::setFixedCubie(int side, int row, int col, int color) {
    setCubie(side,row,  col,  color, 1.0);
} */





