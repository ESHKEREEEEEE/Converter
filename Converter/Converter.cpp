#include <iostream>

enum LengthType {
    kilometers = 1,
    arshin,
    inch
};

enum MassType {
    ton = 1,
    pud,
    ounce
};

enum AreaType {
    square_kilometer = 1,
    square_arshin,
    square_mile
};

class LengthConverter {
public:
    double toMeters(LengthType type, double value) {
        double multiplier = 0;
        if (type == LengthType::arshin) { multiplier = 0.72; }
        else if (type == LengthType::inch) { multiplier = 0.0254; }
        else if (type == LengthType::kilometers) { multiplier = 1000; }
        return multiplier * value;
    }

    double fromMeters(LengthType type, double value) {
        double multiplier = 0;
        if (type == LengthType::arshin) { multiplier =  1/0.72; }
        else if (type == LengthType::inch) { multiplier = 1 / 0.0254; }
        else if (type == LengthType::kilometers) { multiplier = 0.001; }
        return multiplier * value;
    }
};

class MassConverter {
public:
    double toKilograms(MassType type, double value) {
        double multiplier = 0;
        if (type == MassType::pud) { multiplier = 16.380; }
        else if (type == MassType::ounce) { multiplier = 0.0283495; }
        else if (type == MassType::ton) { multiplier = 1000; }
        return multiplier * value;
    }
    double fromKilograms(MassType type, double value) {
        double multiplier = 0;
        if (type == MassType::pud) { multiplier =  1/16.38; }
        else if (type == MassType::ounce) { multiplier = 1/ 0.0283495; }
        else if (type == MassType::ton) { multiplier = 0.001; }
        return multiplier * value;
    }
};

class AreaConverter {
public:
    double toSquareMeters(AreaType type, double value) {
        double multiplier = 0;
        if (type == AreaType::square_arshin) { multiplier = 0.5058; }
        else if (type == AreaType::square_mile) { multiplier = 2590000; }
        else if (type == AreaType::square_kilometer) { multiplier = 1000000; }
        return multiplier * value;
    }
    double fromSquareMeters(AreaType type, double value) {
        return 1;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
