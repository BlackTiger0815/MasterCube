#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include "cubie.h"
#include <iterator>

void Cubie::setColor(int p_color) {
    if ((p_color < COLOR_MIN) || (p_color > COLOR_MAX)) {
        throw std::invalid_argument("Color domain violated: " );
    }
    this->color = p_color;
}

void Cubie::updateProbabilityForSpecificColor(int p_color, float p_probability) {
    if (p_probability < PROBABILITY_MIN || p_probability > PROBABILITY_MAX) {
        throw std::invalid_argument("Probability domain violated");
    }
    if (p_color < COLOR_MIN || p_color > COLOR_MAX) {
        throw std::invalid_argument("Color domain violated");
    }
    std::multimap<int, float>::iterator pos = colorProbabilityPair.find(p_color);
    colorProbabilityPair.erase(pos);
    colorProbabilityPair.insert(std::make_pair(p_color, p_probability));
}

void Cubie::printColorProbabilityPair() {
    std::multimap<int, float>::iterator pos;
    for (pos = colorProbabilityPair.begin(); pos != colorProbabilityPair.end(); ++pos) {
        std::cout << '\t' << "Color: " << pos->first << '\t' << "Probability: " << std::fixed << std::setprecision(3) << pos->second << std::endl;
    }
    std::cout << std::endl;
}

std::string Cubie::toString() {
    std::string prefix = color == -1 ? "." : getColorAsString();
    std::stringstream stream;
    stream << " [" + prefix + " " << std::fixed << std::setprecision(1) << "]"; // std::setw(4) << probability << "]";
    return stream.str();
}
std::string Cubie::getColorAsString(){
    std::ostringstream sstr;
    // fold expression
    sstr << this->color;
    return sstr.str();
}


