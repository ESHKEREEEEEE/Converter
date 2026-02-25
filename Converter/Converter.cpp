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
        //METRIC CONVERSIONS
        case meters:        multiplier = 1;     break;
        case kilometers:    multiplier = 1000;  break;

        //OLD RUSSIAN CONVERSIONS
        case vershok:       multiplier = 0.045; break;
        case pyad:          multiplier = 0.18;  break;
        case lokot:         multiplier = 0.48;  break;
        case arshin:        multiplier = 0.72;  break;
        case sajen:         multiplier = 2.16;  break;
        case versta:        multiplier = 2160;  break;

        //UNSUPPORTED
        default: throw std::invalid_argument("Unsupported type");
        }

        return value * multiplier;
    }
    double fromMeters(LengthType type, double value)
    {
        double multiplier;
        switch (type) {
        //METRIC CONVERSIONS
        case meters:        multiplier = 1;     break;
        case kilometers:    multiplier = 0.001;  break;

        //OLD RUSSIAN CONVERSIONS
        case vershok:       multiplier = 1.0/0.045; break;
        case pyad:          multiplier = 1.0/0.18;  break;
        case lokot:         multiplier = 1.0/0.48;  break;
        case arshin:        multiplier = 1.0/0.72;  break;
        case sajen:         multiplier = 1.0/2.16;  break;
        case versta:        multiplier = 1.0/2160;  break;

        //UNSUPPORTED
        default: throw std::invalid_argument("Unsupported type");
        }

        return value * multiplier;
    }
};

class MassConverter {
    
};

class VolumeConverter {

};

class AreaConverter {

};

int main()
{
    std::cout << "Hello World!\n";
}
