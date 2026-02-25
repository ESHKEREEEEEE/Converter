#include <iostream>
#include <string>
#include <stdexcept>

enum LengthType {
    meters,
    kilometers,
    //Old russian
    versta,
    sajen,
    arshin,
    lokot,
    pyad,
    vershok
};

class LengthConverter {
public:
    double toMeters(LengthType type, double value) 
    {
        double multiplier;
        switch (type) {
        case meters:        multiplier = 1;     break;
        case kilometers:    multiplier = 1000;  break;
        case vershok:       multiplier = 0.045; break;
        default: throw std::invalid_argument("Unsupported type");
        }

        return value * multiplier;
    }
};

class MassConverter {

};

class VolumeConverter {

};

int main()
{
    std::cout << "Hello World!\n";
}
