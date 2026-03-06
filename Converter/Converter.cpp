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

enum VolumeType {
    //Metric system
    liter = 1,
    cubic_meter,
    cubic_centimeter,
    cubic_millimeter,
    cubic_decimeter,

    //USA system
    fluid_ounce,
    fluid_pint,
    fluid_gallon,
    fluid_barrel,
    solid_pint,
    solid_gallon,
    solid_barrel,

    //Old russian system
    bochka,
    korchaga,
    vedro,
    chetvert,
    osmuha,
    vine_bottle,
    vodka_bottle,
    stakan,
    kadka,
    solid_chetvert,
    osmina,
    chetverik,
    garnec
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
        case kilogram:      multiplier = 1;       break;
        case gram:          multiplier = 1000;    break;
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
    double fromSquareMeters(AreaType type, double value) {
        double multiplier;
        switch (type) {
        //METRIC CONVERSIONS
        case square_meter:          multiplier = 1.0/1;          break;
        case square_kilometer:      multiplier = 1.0/1000000;    break;
        case square_centimeter:     multiplier = 1.0/0.0001;     break;
        case square_millimeter:     multiplier = 1.0/0.000001;   break;
        case square_decimeter:      multiplier = 1.0/0.01;       break;

        //USA CONVERSIONS
        case square_mile:           multiplier = 1.0/2590000;    break;
        case square_rod:            multiplier = 1.0/25.293;     break;
        case square_yard:           multiplier = 1.0/0.83613;    break;
        case square_foot:           multiplier = 1.0/0.092903;   break;
        case square_inch:           multiplier = 1.0/0.00064516; break;
        case acre:                  multiplier = 1.0/4046.86;    break;

        //OLD RUSSIAN CONVERSIONS
        case desyatina:             multiplier = 1.0/10930;      break;
        case kopna:                 multiplier = 1.0/1093;       break;
        case square_sajen:          multiplier = 1.0/4.552;      break;
        case square_arshin:         multiplier = 1.0/0.5058;     break;
        case square_vershok:        multiplier = 1.0/0.001976;   break;
        case square_versta:         multiplier = 1.0/1138000;    break;

        //UNSUPPORTED
        default: throw std::invalid_argument("Unsupported type");
        }

        return value * multiplier;
    };
    double toSquareMeters(AreaType type, double value) {
        double multiplier;
        switch (type) {
            //METRIC CONVERSIONS
        case square_meter:          multiplier = 1;          break;
        case square_kilometer:      multiplier = 1000000;    break;
        case square_centimeter:     multiplier = 0.0001;     break;
        case square_millimeter:     multiplier = 0.000001;   break;
        case square_decimeter:      multiplier = 0.01;       break;

            //USA CONVERSIONS
        case square_mile:           multiplier = 2590000;    break;
        case square_rod:            multiplier = 25.293;     break;
        case square_yard:           multiplier = 0.83613;    break;
        case square_foot:           multiplier = 0.092903;   break;
        case square_inch:           multiplier = 0.00064516; break;
        case acre:                  multiplier = 4046.86;    break;

            //OLD RUSSIAN CONVERSIONS
        case desyatina:             multiplier = 10930;      break;
        case kopna:                 multiplier = 1093;       break;
        case square_sajen:          multiplier = 4.552;      break;
        case square_arshin:         multiplier = 0.5058;     break;
        case square_vershok:        multiplier = 0.001976;   break;
        case square_versta:         multiplier = 1138000;    break;

            //UNSUPPORTED
        default: throw std::invalid_argument("Unsupported type");
        }

        return value * multiplier;
    };
};

class VolumeConverter {
public:
    double toLiters(VolumeType type, double value) {
        double multiplier;
        switch (type) {
            //METRIC CONVERSIONS
        case liter:              multiplier = 1;      break;
        case cubic_meter:        multiplier = 1000;      break;
        case cubic_centimeter:   multiplier = 0.001;      break;
        case cubic_millimeter:   multiplier = 0.000001;      break;
        case cubic_decimeter:    multiplier = 1;      break;

            //USA CONVERSIONS
        case fluid_ounce:        multiplier = 0.02956;      break;
        case fluid_pint:         multiplier = 0.473;      break;
        case fluid_gallon:       multiplier = 3.785;      break;
        case fluid_barrel:       multiplier = 119.2;      break;
        case solid_pint:         multiplier = 0.55;      break;
        case solid_gallon:       multiplier = 4.405;      break;
        case solid_barrel:       multiplier = 115.6;      break;

            //OLD RUSSIAN CONVERSIONS
        case bochka:             multiplier = 491.96;      break;
        case korchaga:           multiplier = 24.59882;      break;
        case vedro:              multiplier = 12.29941;      break;
        case chetvert:           multiplier = 3.0748;      break;
        case osmuha:             multiplier = 1.5374;      break;
        case vine_bottle:        multiplier = 0.7687;      break;
        case vodka_bottle:       multiplier = 0.6;      break;
        case stakan:             multiplier = 0.273;      break;
        case kadka:              multiplier = 839.69;      break;
        case solid_chetvert:     multiplier = 209.9225;      break;
        case osmina:             multiplier = 104.96125;      break;
        case chetverik:          multiplier = 26.2387;      break;
        case garnec:             multiplier = 3.2798;      break;

            //UNSUPPORTED
        default: throw std::invalid_argument("Unsupported type");
        }

        return value * multiplier;
    }

    double fromLiters(VolumeType type, double value) { return 0; }
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
