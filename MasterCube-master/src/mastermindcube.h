#include <iostream>
#include "cubie.h"

class MastermindCube {



public:
    static const int MAX_COL_INDEX = 3;
    static const int MAX_ROW_INDEX = 3;
    static const int MAX_SIDE_INDEX = 6;

    MastermindCube();
    void print();
    void printRow(int i, int j);
    void printSide(int i);

    void setCubie(int side, int row, int col, int color); //, float probability);
    void setFixedCubie(int side, int row, int col, int color);
    bool isCenterCubie(int side, int row, int col){return row == 1 && col == 1;}



    ~MastermindCube();
private:
    Cubie cube[MAX_SIDE_INDEX][MAX_ROW_INDEX][MAX_COL_INDEX];
    std::string filler;
};
