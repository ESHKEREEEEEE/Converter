#include <iostream>
#include <string>
#include <stdexcept>

//Types enum for length conversion
enum LengthType {
    //Metric system
    meters = 1,
    centimeters,
    decimeters,
    millimeters,
    kilometers,

    //Old russian

    versta,
    sajen,
    arshin,
    lokot,
    pyad,
    vershok,

    //USA

    mile,
    yard,
    foot,
    inch,
    rod,
    chain,
    furlong
};

//Types enum for mass conversion
enum MassType {
    //Metric system
    kilogram = 1,
    gram,
    ton,

    //USA
    ounce,
    pound,
    stone,
    tod,
    quintal,
    short_ton,

    //Old russian
    berkovec,
    pud,
    ru_pound,
    lot,
    zolotnik
};

enum AreaType {
    //Metric system
    square_meter = 1,
    square_kilometer,
    square_centimeter,
    square_millimeter,
    square_decimeter,

    //USA

    square_mile,
    square_rod,
    square_yard,
    square_foot,
    square_inch,
    acre,

    //Old russian

    desyatina,
    kopna,
    square_sajen,
    square_arshin,
    square_vershok,
    square_versta
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
        case centimeters:   multiplier = 0.01;  break;
        case millimeters:   multiplier = 0.001; break;
        case decimeters:    multiplier = 0.1;   break;

        //OLD RUSSIAN CONVERSIONS
        case vershok:       multiplier = 0.045; break;
        case pyad:          multiplier = 0.18;  break;
        case lokot:         multiplier = 0.48;  break;
        case arshin:        multiplier = 0.72;  break;
        case sajen:         multiplier = 2.16;  break;
        case versta:        multiplier = 2160;  break;

        //USA CONVERSIONS
        case mile:          multiplier = 1609.344;  break;
        case yard:          multiplier = 0.9144;    break;
        case foot:          multiplier = 0.3048;    break;
        case inch:          multiplier = 0.0254;    break;
        case rod:           multiplier = 5.0292;    break;
        case chain:         multiplier = 20.1168;   break;
        case furlong:       multiplier = 201.168;   break;

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
        case meters:        multiplier = 1;      break;
        case kilometers:    multiplier = 0.001;  break;
        case centimeters:   multiplier = 100;    break;
        case millimeters:   multiplier = 1000;   break;
        case decimeters:    multiplier = 10;     break;

        //OLD RUSSIAN CONVERSIONS
        case vershok:       multiplier = 1.0/0.045; break;
        case pyad:          multiplier = 1.0/0.18;  break;
        case lokot:         multiplier = 1.0/0.48;  break;
        case arshin:        multiplier = 1.0/0.72;  break;
        case sajen:         multiplier = 1.0/2.16;  break;
        case versta:        multiplier = 1.0/2160;  break;

        //USA CONVERSIONS
        case mile:          multiplier = 1.0/1609.344;  break;
        case yard:          multiplier = 1.0/0.9144;    break;
        case foot:          multiplier = 1.0/0.3048;    break;
        case inch:          multiplier = 1.0/0.0254;    break;
        case rod:           multiplier = 1.0/5.0292;    break;
        case chain:         multiplier = 1.0/20.1168;   break;
        case furlong:       multiplier = 1.0/201.168;   break;

        //UNSUPPORTED
        default: throw std::invalid_argument("Unsupported type");
        }

        return value * multiplier;
    }
};

class MassConverter {
public:
    double toKilograms(MassType type, double value) {
        double multiplier;
        switch (type) {
        //METRIC CONVERSIONS
        case kilogram:      multiplier = 1;      break;
        case gram:          multiplier = 0.001;  break;
        case ton:           multiplier = 1000;   break;

        //USA CONVERSIONS
        case ounce:         multiplier = 0.0283495;   break;
        case pound:         multiplier = 0.453592;    break;
        case stone:         multiplier = 6.3502;      break;
        case tod:           multiplier = 12.7;        break;
        case quintal:       multiplier = 45.36;       break;
        case short_ton:     multiplier = 907.185;     break;

        //OLD RUSSIAN CONVERSIONS
        case berkovec:      multiplier = 163.8;       break;
        case pud:           multiplier = 16.380;      break;
        case ru_pound:      multiplier = 0.4095124;   break;
        case lot:           multiplier = 0.01279726;  break;
        case zolotnik:      multiplier = 0.0042657;   break;

        //UNSUPPORTED
        default: throw std::invalid_argument("Unsupported type");
        }

        return value * multiplier;
    }
    double fromKilograms(MassType type, double value) {
        double multiplier;
        switch (type) {
            //METRIC CONVERSIONS
        case kilogram:      multiplier = 1;      break;
        case gram:          multiplier = 1000;  break;
        case ton:           multiplier = 0.001;   break;

            //USA CONVERSIONS
        case ounce:         multiplier = 1.0/0.0283495;   break;
        case pound:         multiplier = 1.0/0.453592;    break;
        case stone:         multiplier = 1.0/6.3502;      break;
        case tod:           multiplier = 1.0/12.7;        break;
        case quintal:       multiplier = 1.0/45.36;       break;
        case short_ton:     multiplier = 1.0/907.185;     break;

            //OLD RUSSIAN CONVERSIONS
        case berkovec:      multiplier = 1.0/163.8;       break;
        case pud:           multiplier = 1.0/16.380;      break;
        case ru_pound:      multiplier = 1.0/0.4095124;   break;
        case lot:           multiplier = 1.0/0.01279726;  break;
        case zolotnik:      multiplier = 1.0/0.0042657;   break;

            //UNSUPPORTED
        default: throw std::invalid_argument("Unsupported type");
        }

        return value * multiplier;
    }
};

class AreaConverter {
public:
    double fromSquareMeters(AreaType type, double value) {};
};

class VolumeConverter {

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
