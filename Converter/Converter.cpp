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
        return 0.001 * value;
    }
};

class AreaConverter {

};

int main()
{
    std::cout << "Hello World!\n";
}
