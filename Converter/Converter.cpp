#include <iostream>
#include <string>
#include <stdexcept>

class LengthConverter {
public:
    double toMeters(std::string type, double value) 
    {
        if (type == "km") return value * 1000;

        throw std::invalid_argument("Works only with km");
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
