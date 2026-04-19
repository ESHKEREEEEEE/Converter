#include <iostream>

enum LengthType {
    kilometers = 1,
    inch,
    arshin
};

enum MassType {
    ton = 1,
    ounce,
    pud
};

enum AreaType {
    square_kilometer = 1,
    square_mile,
    square_arshin
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
        double multiplier = 0;
        if (type == AreaType::square_arshin) { multiplier = 1/0.5058; }
        else if (type == AreaType::square_mile) { multiplier = 1.0 / 2590000; }
        else if (type == AreaType::square_kilometer) { multiplier = 0.000001; }
        return multiplier * value;
    }
};

int main()
{
    std::cout << "Welcome to unit conversion program!" << std::endl;

    std::cout << "What unit do you have? \n 1. Length \n 2. Mass \n 3. Area" << std::endl;
    int unit;
    std::cin >> unit;

    int in_type;
    double amount;
    int out_type;
    switch (unit) {
    case 1: //Length
        LengthConverter lc;

        std::cout <<
            "What length type do you have?\n"
            "===Metric===\n"
            "1. Kilometers\n\n"

            "===USA===\n"
            "2. Inch\n\n"

            "===Old russian==\n"
            "3. Arshin\n"
            << std::endl;
        std::cin >> in_type;
        std::cout << "How much?" << std::endl;
        std::cin >> amount;
        std::cout <<
            "What length type do you need?\n"
            "===Metric===\n"
            "1. Kilometers\n\n"

            "===USA===\n"
            "2. Inch\n\n"

            "===Old russian==\n"
            "3. Arshin\n"
            << std::endl;
        std::cin >> out_type;
        try {
            std::cout << "Result " << lc.fromMeters((LengthType)out_type, lc.toMeters((LengthType)in_type, amount)) << std::endl;
        }
        catch (std::invalid_argument e) { std::cout << e.what() << std::endl; }
        break;
    case 2: //Mass
        MassConverter mc;
        std::cout <<
            "What mass type do you have?\n"
            "===Metric system===\n"
            "1. Ton\n\n"

            "===USA===\n"
            "2. Ounce\n\n"

            "===Old russian===\n"
            "3. Pud\n"
            << std::endl;
        std::cin >> in_type;
        std::cout << "How much?" << std::endl;
        std::cin >> amount;
        std::cout <<
            "What mass type do you need?\n"
            "===Metric system===\n"
            "1. Ton\n\n"

            "===USA===\n"
            "2. Ounce\n\n"

            "===Old russian===\n"
            "3. Pud\n"
            << std::endl;
        std::cin >> out_type;
        try {
            std::cout << "Result " << mc.fromKilograms((MassType)out_type, mc.toKilograms((MassType)in_type, amount)) << std::endl;
        }
        catch (std::invalid_argument e) { std::cout << e.what() << std::endl; }
        break;
    case 3: //Area
        AreaConverter ac;
        std::cout <<
            "What area type do you have?\n"
            "===Metric===\n"
            "1. Square kilometer\n"

            "===USA===\n"
            "2. Square mile\n\n"

            "===Old russian===\n"
            "3. Square arshin\n\n"
            << std::endl;
        std::cin >> in_type;
        std::cout << "How much?" << std::endl;
        std::cin >> amount;
        std::cout <<
            "What area type do you need?\n"
            "===Metric===\n"
            "1. Square kilometer\n"

            "===USA===\n"
            "2. Square mile\n\n"

            "===Old russian===\n"
            "3. Square arshin\n\n"
            << std::endl;
        std::cin >> out_type;
        try {
            std::cout << "Result " << ac.fromSquareMeters((AreaType)out_type, ac.toSquareMeters((AreaType)in_type, amount)) << std::endl;
        }
        catch (std::invalid_argument e) { std::cout << e.what() << std::endl; }
        break;
    default:
        throw std::invalid_argument("Unsupported unit");
    }

    return 0;
}
