//#include "stdafx.h"
#include <iostream>
//#include <stdlib.h>
//#include <string>
//#include <cmath>
//#include <time.h>
//#include <stdio.h>
#include <map>

class Cubie {

private:
    int color; // hier über die Setter-Methode Farbe eintragen
    /* float probability; */

    std::multimap<int, float> colorProbabilityPair; // hier sind noch alle möglichen Farben mit ihren jeweiligen Prob gespeichert


public:
    static const int COLOR_MIN = 0;
    static const int COLOR_MAX = 5;
    constexpr static const float PROBABILITY_MIN = 0.0;
    constexpr static const float PROBABILITY_MAX = 1.0;

    Cubie() {
        color = -1;
        // probability = 0.0F;
        for (int i = 0; i < 6; i++) {
            colorProbabilityPair.insert(std::make_pair(i, (1/6.f)));
        }
    };

    ~Cubie() = default;


    void setColor(int p_color) noexcept(false);

    int getColor() { return color; }

    void printColorProbabilityPair();

    void updateProbabilityForSpecificColor(int p_color, float p_probability);


    // DELETE? void setProbability(float probability) noexcept(false);

    // CHANGE to get prob for specific color float getProbability() { return probability; }

    std::string getColorAsString();

    std::string toString();

    //=============Check Functions=========================================================

    // bool fixedColor() { return probability == 1; } // ist Farbe schon sicher bekannt

    bool isCenterField(); // ueberpruefe ob Mittelfeld anhand Indizes

    bool isEdgeField(); // ueberpruefe ob Kantenfeld, noch nicht implementiert

    bool isCornerField();    // ueberpruefe ob Eckfeld, noch nicht implementiert


    void print() { std::cout << "Color: " << color << std::endl; }


};


