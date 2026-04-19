#include <iostream>

enum LengthType {
    kilometers = 1,
    arshin
};

class LengthConverter {
public:
    double toMeters(LengthType type, int value) {
        if (type == LengthType::arshin) { return 0.72; }
        return 1000 * value;
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
