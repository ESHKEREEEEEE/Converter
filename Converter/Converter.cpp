#include <iostream>

enum LengthType {
    kilometers = 1,
    arshin,
    inch
};

class LengthConverter {
public:
    double toMeters(LengthType type, int value) {
        double multiplier = 0;
        if (type == LengthType::arshin) { multiplier = 0.72; }
        else if (type == LengthType::inch) { multiplier = 0.0254; }
        else if (type == LengthType::kilometers) { multiplier = 1000; }
        return multiplier * value;
    }

    double fromMeters(LengthType type, int value) {
        if (type == LengthType::arshin) { return 12.5; }
        return 0.001 * value;
    }
};

class MassConverter {

};

class AreaConverter {

};

int main()
{
    std::cout << "Hello World!\n";
}
