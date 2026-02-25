#include <iostream>
#include <string>
#include <stdexcept>

class LengthConverter {
public:
    double toMeters(std::string type, double value) 
    {
        if (type == "km" && value == 1) return 1000;

        throw std::invalid_argument("Works only with 1km");
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
