#include <iostream>

enum LengthType {
    kilometers = 1
};

class LengthConverter {
public:
    int toMeters(LengthType type, int value) {
        return 1000;
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
