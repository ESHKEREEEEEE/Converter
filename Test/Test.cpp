#include "pch.h"
#include "CppUnitTest.h"
#include "../Converter/Converter.cpp"

#define EPS 0.000001

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CreationTests
{
	TEST_CLASS(CreationTests)
	{
	public:
		TEST_METHOD(LengthConverterClassCreation)
		{
			LengthConverter* lc = new LengthConverter();
			Assert::IsNotNull(lc);
		}
		TEST_METHOD(MassConverterClassCreation)
		{
			MassConverter* mc = new MassConverter();
			Assert::IsNotNull(mc);
		}
		TEST_METHOD(AreaConverterClassCreation) {
			AreaConverter* ac = new AreaConverter();
			Assert::IsNotNull(ac);
		}
	};
}

namespace LengthConversionTests 
{
	TEST_CLASS(MetricConversionTests)
	{
		//toMeters
		TEST_METHOD(LengthConverter_Convert1KilometerToMeters_Returns1000) 
		{
			LengthConverter lc;
			double input = 1;
			double target = 1000;
			LengthType type = LengthType::kilometers;
			double conversion_result = lc.toMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue((abs(conversion_result - target) <= EPS), msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert10KilometersToMeters_Returns10000)
		{
			LengthConverter lc;
			double input = 10;
			double target = 10000;
			LengthType type = LengthType::kilometers;
			double conversion_result = lc.toMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		//fromMeters
		TEST_METHOD(LengthConverter_Convert1MeterToKilometers_Returns0p001) {
			LengthConverter lc;
			double input = 1;
			double target = 0.001;
			LengthType type = LengthType::kilometers;
			double conversion_result = lc.fromMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert10MeterToKilometers_Returns0p01) {
			LengthConverter lc;
			double input = 10;
			double target = 0.01;
			LengthType type = LengthType::kilometers;
			double conversion_result = lc.fromMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
	};
	TEST_CLASS(OldRussianConversionTests) {
		//toMeters
		TEST_METHOD(LengthConverter_Convert1ArshinToMeters_Returns0p72) {
			LengthConverter lc;
			double input = 1;
			double target = 0.72;
			LengthType type = LengthType::arshin;
			double conversion_result = lc.toMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert10ArshinToMeters_Returns7p2) {
			LengthConverter lc;
			double input = 10;
			double target = 7.2;
			LengthType type = LengthType::arshin;
			double conversion_result = lc.toMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		//fromMeters
		TEST_METHOD(LengthConverter_Convert9MetersToArshin_Returns12p5) {
			LengthConverter lc;
			double input = 9;
			double target = 12.5;
			LengthType type = LengthType::arshin;
			double conversion_result = lc.fromMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert18MetersToArshin_Returns25) {
			LengthConverter lc;
			double input = 18;
			double target = 25;
			LengthType type = LengthType::arshin;
			double conversion_result = lc.fromMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
	};
	TEST_CLASS(USAConversionTests) {
		//toMeters
		TEST_METHOD(LengthConverter_Convert1InchToMeters_Returns0p0254) {
			LengthConverter lc;
			double input = 1;
			double target = 0.0254;
			LengthType type = LengthType::inch;
			double conversion_result = lc.toMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert10InchToMeters_Returns0p254) {
			LengthConverter lc;
			double input = 10;
			double target = 0.254;
			LengthType type = LengthType::inch;
			double conversion_result = lc.toMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		//fromMeters
		TEST_METHOD(LengthConverter_Convert0p0254MetersToInches_Returns1) {
			LengthConverter lc;
			double input = 0.0254;
			double target = 1;
			LengthType type = LengthType::inch;
			double conversion_result = lc.fromMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert0p254MetersToInches_Returns10) {
			LengthConverter lc;
			double input = 0.254;
			double target = 10;
			LengthType type = LengthType::inch;
			double conversion_result = lc.fromMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
	};
}

namespace MassConversionTests {
	TEST_CLASS(MetricConversionTests) {
		//toKilograms
		TEST_METHOD(MassConverter_Convert1TonToKilograms_Returns1000) {
			MassConverter mc;
			double input = 1;
			double target = 1000;
			MassType type = MassType::ton;
			double conversion_result = mc.toKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(MassConverter_Convert10TonToKilograms_Returns10000) {
			MassConverter mc;
			double input = 10;
			double target = 10000;
			MassType type = MassType::ton;
			double conversion_result = mc.toKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		//fromKilograms
		TEST_METHOD(MassConverter_Convert1KilogramToTons_Returns0p001) {
			MassConverter mc;
			double input = 1;
			double target = 0.001;
			MassType type = MassType::ton;
			double conversion_result = mc.fromKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" kilograms" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(MassConverter_Convert10KilogramToTons_Returns0p01) {
			MassConverter mc;
			double input = 10;
			double target = 0.01;
			MassType type = MassType::ton;
			double conversion_result = mc.fromKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" kilograms" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
	};
	TEST_CLASS(OldRussianConversionTests) {
		//toKilograms
		TEST_METHOD(MassConverter_Convert1PudToKilograms_Returns16p380) {
			MassConverter mc;
			double input = 1;
			double target = 16.380;
			MassType type = MassType::pud;
			double conversion_result = mc.toKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(MassConverter_Convert10PudToKilograms_Returns163p80) {
			MassConverter mc;
			double input = 10;
			double target = 163.80;
			MassType type = MassType::pud;
			double conversion_result = mc.toKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		//fromKilograms
		TEST_METHOD(MassConverter_Convert16p38KilogramToPuds_Returns1) {
			MassConverter mc;
			double input = 16.38;
			double target = 1;
			MassType type = MassType::pud;
			double conversion_result = mc.fromKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" kilograms" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(MassConverter_Convert163p8KilogramToPuds_Returns10) {
			MassConverter mc;
			double input = 163.8;
			double target = 10;
			MassType type = MassType::pud;
			double conversion_result = mc.fromKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" kilograms" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
	};
	TEST_CLASS(USAConversionTests) {
		//toKilograms
		TEST_METHOD(MassConverter_Convert1OunceToKilograms_Returns0p0283495) {
			MassConverter mc;
			double input = 1;
			double target = 0.0283495;
			MassType type = MassType::ounce;
			double conversion_result = mc.toKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}

		TEST_METHOD(MassConverter_Convert10OunceToKilograms_Returns0p283495) {
			MassConverter mc;
			double input = 10;
			double target = 0.283495;
			MassType type = MassType::ounce;
			double conversion_result = mc.toKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		//fromKilograms
		TEST_METHOD(MassConverter_Convert1KilogramToOunces_Returns35p2739907) {
			MassConverter mc;
			double input = 1;
			double target = 35.2739907;
			MassType type = MassType::ounce;
			double conversion_result = mc.fromKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" kilograms" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(MassConverter_Convert10KilogramToOunces_Returns352p739907) {
			MassConverter mc;
			double input = 10;
			double target = 352.739907;
			MassType type = MassType::ounce;
			double conversion_result = mc.fromKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" kilograms" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
	};
}

namespace AreaConversionTests {
	TEST_CLASS(MetricSystemConversion) {
		TEST_METHOD(AreaConverter_Convert1SquareKilometerToSquareMeters_Returns1000000) {
			AreaConverter ac;
			double input = 1;
			double target = 1000000;
			AreaType type = AreaType::square_kilometer;
			double conversion_result = ac.toSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
	};
}