#include <iostream>
#include <string>
#include <stdexcept>

//Types enum for length conversion
enum LengthType {
    meters = 1,
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
    //Converts length from parameter 1 type to meters
    //Param 1 - type for conversion from LengthType enum
    //Param 2 - double value to convert
    //Return result of conversion
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

    //Converts length in meters to param 1 type 
    //Param 1 - type for conversion from LengthType enum
    //Param 2 - double value to convert
    //Return result of conversion
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
    std::cout << "Welcome to unit conversion program!" << std::endl;

    std::cout << "What unit type do you have? \n 1. Meter \n 2. Kilometer \n 3. Versta \n 4. Sajen \n 5. Arshin \n 6. Lokot \n 7. Pyad \n 8. Vershok" << std::endl;
    int have;
    std::cin >> have;

    std::cout << "How many?" << std::endl;
    double value;
    std::cin >> value;

    std::cout << "What unit type do you need? \n 1. Meter \n 2. Kilometer \n 3. Versta \n 4. Sajen \n 5. Arshin \n 6. Lokot \n 7. Pyad \n 8. Vershok" << std::endl;
    int need;
    std::cin >> need;

    LengthConverter lc;
    try {
        std::cout << "Result " << lc.fromMeters((LengthType)need, lc.toMeters((LengthType)have, value)) << std::endl;
    }
    catch (std::invalid_argument e) { std::cout << e.what() << std::endl; }

    return 0;
}
