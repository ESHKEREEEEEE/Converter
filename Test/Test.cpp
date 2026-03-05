#include "pch.h"
#include "CppUnitTest.h"
#include "../Converter/Converter.cpp"

#define EPS 0.0000001

//Tests for unit converters
//p in name of tests means point (0p045 == 0.045)

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace CreationTests 
{
	TEST_CLASS(CreationTests)
	{
	public:
		TEST_METHOD(LengthConverterClassCreation)
		{
			LengthConverter* lc = new LengthConverter();
			Assert::IsNotNull(lc, L"LengthConverter is not created properly (got nullptr)");
			delete lc;
		}
		TEST_METHOD(MassConverterClassCreation)
		{
			MassConverter* mc = new MassConverter();
			Assert::IsNotNull(mc, L"MassConverter is not created properly (got nullptr)");
			delete mc;
		}
		TEST_METHOD(VolumeConverterClassCreation)
		{
			VolumeConverter* vc = new VolumeConverter();
			Assert::IsNotNull(vc, L"VolumeConverter is not created properly (got nullptr)");
			delete vc;
		}
		TEST_METHOD(AreaConverterClassCreation)
		{
			AreaConverter* ac = new AreaConverter();
			Assert::IsNotNull(ac, L"AreaConverter is not created properly (got nullptr)");
			delete ac;
		}
	};
}

namespace ConversionToMetersTests
{
	TEST_CLASS(MetricSystemConversionTests) {
	public:
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
		TEST_METHOD(LengthConverter_Convert1CentimeterToMeters_Returns0p01)
		{
			LengthConverter lc;
			double input = 1;
			double target = 0.01;
			LengthType type = LengthType::centimeters;
			double conversion_result = lc.toMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert1DecimeterToMeters_Returns0p1)
		{
			LengthConverter lc;
			double input = 1;
			double target = 0.1;
			LengthType type = LengthType::decimeters;
			double conversion_result = lc.toMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert1MillimeterToMeters_Returns0p001)
		{
			LengthConverter lc;
			double input = 1;
			double target = 0.001;
			LengthType type = LengthType::millimeters;
			double conversion_result = lc.toMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
	};

	TEST_CLASS(OldRussianSystemConversionTests) {
	public:
		TEST_METHOD(LengthConverter_Convert1VershokToMeters_Returns0p045) {
			LengthConverter lc;
			double input = 1;
			double target = 0.045;
			LengthType type = LengthType::vershok;
			double conversion_result = lc.toMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert1PyadToMeters_Returns0p18) {
			LengthConverter lc;
			double input = 1;
			double target = 0.18;
			LengthType type = LengthType::pyad;
			double conversion_result = lc.toMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert1LokotToMeters_Returns0p48) {
			LengthConverter lc;
			double input = 1;
			double target = 0.48;
			LengthType type = LengthType::lokot;
			double conversion_result = lc.toMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
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
		TEST_METHOD(LengthConverter_Convert1SajenToMeters_Returns2p16) {
			LengthConverter lc;
			double input = 1;
			double target = 2.16;
			LengthType type = LengthType::sajen;
			double conversion_result = lc.toMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert1VerstaToMeters_Returns2160) {
			LengthConverter lc;
			double input = 1;
			double target = 2160;
			LengthType type = LengthType::versta;
			double conversion_result = lc.toMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
	};

	TEST_CLASS(USASystemConversionTests) {
		TEST_METHOD(LengthConverter_Convert1MileToMeters_Returns1609p344) {
			LengthConverter lc;
			double input = 1;
			double target = 1609.344;
			LengthType type = LengthType::mile;
			double conversion_result = lc.toMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert1YardToMeters_Returns0p9144) {
			LengthConverter lc;
			double input = 1;
			double target = 0.9144;
			LengthType type = LengthType::yard;
			double conversion_result = lc.toMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert1FootToMeters_Returns0p3048) {
			LengthConverter lc;
			double input = 1;
			double target = 0.3048;
			LengthType type = LengthType::foot;
			double conversion_result = lc.toMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
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
		TEST_METHOD(LengthConverter_Convert1RodToMeters_Returns5p0292) {
			LengthConverter lc;
			double input = 1;
			double target = 5.0292;
			LengthType type = LengthType::rod;
			double conversion_result = lc.toMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert1ChainToMeters_Returns20p1168) {
			LengthConverter lc;
			double input = 1;
			double target = 20.1168;
			LengthType type = LengthType::chain;
			double conversion_result = lc.toMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert1FurlongToMeters_Returns201p168) {
			LengthConverter lc;
			double input = 1;
			double target = 201.168;
			LengthType type = LengthType::furlong;
			double conversion_result = lc.toMeters(type, input);
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

namespace ConversionFromMetersTests
{
	TEST_CLASS(MetricSystemConversionTests) {
	public:
		TEST_METHOD(LengthConverter_Convert1MeterToKilometers_Returns0p001) {
			LengthConverter lc;
			double input = 1;
			double target = 0.001;
			LengthType type = LengthType::kilometers;
			double conversion_result = lc.fromMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" meters" +
				+ L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert10MetersToKilometers_Returns0p01) {
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
		TEST_METHOD(LengthConverter_Convert1MeterToCentimeters_Returns100) {
			LengthConverter lc;
			double input = 1;
			double target = 100;
			LengthType type = LengthType::centimeters;
			double conversion_result = lc.fromMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert1MeterToDecimeters_Returns10) {
			LengthConverter lc;
			double input = 1;
			double target = 10;
			LengthType type = LengthType::decimeters;
			double conversion_result = lc.fromMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert1MeterToMillimeters_Returns1000) {
			LengthConverter lc;
			double input = 1;
			double target = 1000;
			LengthType type = LengthType::millimeters;
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

	TEST_CLASS(OldRussianSystemConversionTests) {
	public:
		TEST_METHOD(LengthConverter_Convert9MetersToVershok_Returns200) {
			LengthConverter lc;
			double input = 9;
			double target = 200;
			LengthType type = LengthType::vershok;
			double conversion_result = lc.fromMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert4p5MetersToPyad_Returns25) {
			LengthConverter lc;
			double input = 4.5;
			double target = 25;
			LengthType type = LengthType::pyad;
			double conversion_result = lc.fromMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert3MetersToLokot_Returns6p25) {
			LengthConverter lc;
			double input = 3;
			double target = 6.25;
			LengthType type = LengthType::lokot;
			double conversion_result = lc.fromMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
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
		TEST_METHOD(LengthConverter_Convert2p16MetersToSajen_Returns1) {
			LengthConverter lc;
			double input = 2.16;
			double target = 1;
			LengthType type = LengthType::sajen;
			double conversion_result = lc.fromMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert2160MetersToVersta_Returns1) {
			LengthConverter lc;
			double input = 2160;
			double target = 1;
			LengthType type = LengthType::versta;
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

	TEST_CLASS(USASystemConversionTests) {
		TEST_METHOD(LengthConverter_Convert1609p344MetersToMiles_Returns1) {
			LengthConverter lc;
			double input = 1609.344;
			double target = 1;
			LengthType type = LengthType::mile;
			double conversion_result = lc.fromMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert0p9144MetersToYards_Returns1) {
			LengthConverter lc;
			double input = 0.9144;
			double target = 1;
			LengthType type = LengthType::yard;
			double conversion_result = lc.fromMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert0p3048MetersToFoots_Returns1) {
			LengthConverter lc;
			double input = 0.3048;
			double target = 1;
			LengthType type = LengthType::foot;
			double conversion_result = lc.fromMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
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
		TEST_METHOD(LengthConverter_Convert5p0292MetersToRods_Returns1) {
			LengthConverter lc;
			double input = 5.0292;
			double target = 1;
			LengthType type = LengthType::rod;
			double conversion_result = lc.fromMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert20p1168MetersToChain_Returns1) {
			LengthConverter lc;
			double input = 20.1168;
			double target = 1;
			LengthType type = LengthType::chain;
			double conversion_result = lc.fromMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(LengthConverter_Convert201p168MetersToFurlongs_Returns1) {
			LengthConverter lc;
			double input = 201.168;
			double target = 1;
			LengthType type = LengthType::furlong;
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

namespace ConversionToKilogramsTests {
	TEST_CLASS(MetricSystemConversionTests) {
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
		TEST_METHOD(MassConverter_Convert1GramToKilograms_Returns0p001) {
			MassConverter mc;
			double input = 1;
			double target = 0.001;
			MassType type = MassType::gram;
			double conversion_result = mc.toKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
	};
	TEST_CLASS(USASystemConversionTests) {
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
		TEST_METHOD(MassConverter_Convert1PoundToKilograms_Returns0p453592) {
			MassConverter mc;
			double input = 1;
			double target = 0.453592;
			MassType type = MassType::pound;
			double conversion_result = mc.toKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(MassConverter_Convert1StoneToKilograms_Returns6p3502) {
			MassConverter mc;
			double input = 1;
			double target = 6.3502;
			MassType type = MassType::stone;
			double conversion_result = mc.toKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(MassConverter_Convert1TodToKilograms_Returns12p7) {
			MassConverter mc;
			double input = 1;
			double target = 12.7;
			MassType type = MassType::tod;
			double conversion_result = mc.toKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(MassConverter_Convert1QuintalToKilograms_Returns45p36) {
			MassConverter mc;
			double input = 1;
			double target = 45.36;
			MassType type = MassType::quintal;
			double conversion_result = mc.toKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(MassConverter_Convert1ShortTonToKilograms_Returns907p185) {
			MassConverter mc;
			double input = 1;
			double target = 907.185;
			MassType type = MassType::short_ton;
			double conversion_result = mc.toKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
	};
	TEST_CLASS(OldRussianSystemConversionTests) {
		TEST_METHOD(MassConverter_Convert1BerkovecToKilograms_Returns163p8) {
			MassConverter mc;
			double input = 1;
			double target = 163.8;
			MassType type = MassType::berkovec;
			double conversion_result = mc.toKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
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
		TEST_METHOD(MassConverter_Convert1RuPoundToKilograms_Returns0p4095124) {
			MassConverter mc;
			double input = 1;
			double target = 0.4095124;
			MassType type = MassType::ru_pound;
			double conversion_result = mc.toKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(MassConverter_Convert1LotToKilograms_Returns0p01279726) {
			MassConverter mc;
			double input = 1;
			double target = 0.01279726;
			MassType type = MassType::lot;
			double conversion_result = mc.toKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(MassConverter_Convert1ZolotnikToKilograms_Returns0p0042657) {
			MassConverter mc;
			double input = 1;
			double target = 0.0042657;
			MassType type = MassType::zolotnik;
			double conversion_result = mc.toKilograms(type, input);
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

namespace ConversionFromKilogramsTests {
	TEST_CLASS(MetricSystemConversionTests) {
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
		TEST_METHOD(MassConverter_Convert1KilogramToGrams_Returns1000) {
			MassConverter mc;
			double input = 1;
			double target = 1000;
			MassType type = MassType::gram;
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
	TEST_CLASS(USASystemConversionTests) {
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
		TEST_METHOD(MassConverter_Convert1KilogramToPounds_Returns2p20462442) {
			MassConverter mc;
			double input = 1;
			double target = 2.20462442;
			MassType type = MassType::pound;
			double conversion_result = mc.fromKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" kilograms" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(MassConverter_Convert1KilogramToStones_Returns0p157475355) {
			MassConverter mc;
			double input = 1;
			double target = 0.157475355;
			MassType type = MassType::stone;
			double conversion_result = mc.fromKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" kilograms" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(MassConverter_Convert1KilogramToTods_Returns0p0787401575) {
			MassConverter mc;
			double input = 1;
			double target = 0.0787401575;
			MassType type = MassType::tod;
			double conversion_result = mc.fromKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" kilograms" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(MassConverter_Convert1KilogramToQuintal_Returns0p0220458554) {
			MassConverter mc;
			double input = 1;
			double target = 0.0220458554;
			MassType type = MassType::quintal;
			double conversion_result = mc.fromKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" kilograms" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(MassConverter_Convert907p185KilogramToShortTons_Returns1) {
			MassConverter mc;
			double input = 907.185;
			double target = 1;
			MassType type = MassType::short_ton;
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
	TEST_CLASS(OldRussianSystemConversionTests) {
		TEST_METHOD(MassConverter_Convert163p8KilogramToBerkovec_Returns1) {
			MassConverter mc;
			double input = 163.8;
			double target = 1;
			MassType type = MassType::berkovec;
			double conversion_result = mc.fromKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" kilograms" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
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
		TEST_METHOD(MassConverter_Convert1KilogramToRuPounds_Returns2p4419285) {
			MassConverter mc;
			double input = 1;
			double target = 2.4419285;
			MassType type = MassType::ru_pound;
			double conversion_result = mc.fromKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" kilograms" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(MassConverter_Convert0p01279726KilogramToLots_Returns1) {
			MassConverter mc;
			double input = 0.01279726;
			double target = 1;
			MassType type = MassType::lot;
			double conversion_result = mc.fromKilograms(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" kilograms" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(MassConverter_Convert0p0042657KilogramToZolotniks_Returns1) {
			MassConverter mc;
			double input = 0.0042657;
			double target = 1;
			MassType type = MassType::zolotnik;
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

namespace ConversionFromSquareMetersTests {
	TEST_CLASS(MetricSystemConversionTests) {
		TEST_METHOD(AreaConverter_Convert1000000SquareMetersToSquareKilometers_Returns1) {
			AreaConverter ac;
			double input = 1000000;
			double target = 1;
			AreaType type = AreaType::square_kilometer;
			double conversion_result = ac.fromSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" square meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert0p0001SquareMetersToSquareCentimeters_Returns1) {
			AreaConverter ac;
			double input = 0.0001;
			double target = 1;
			AreaType type = AreaType::square_centimeter;
			double conversion_result = ac.fromSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" square meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert0p000001SquareMetersToSquareMillimeters_Returns1) {
			AreaConverter ac;
			double input = 0.000001;
			double target = 1;
			AreaType type = AreaType::square_millimeter;
			double conversion_result = ac.fromSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" square meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert0p01SquareMetersToSquareDecimeters_Returns1) {
			AreaConverter ac;
			double input = 0.01;
			double target = 1;
			AreaType type = AreaType::square_decimeter;
			double conversion_result = ac.fromSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" square meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
	};
	TEST_CLASS(USASystemConversionTests) {
		TEST_METHOD(AreaConverter_Convert2590000SquareMetersToSquareMiles_Returns1) {
			AreaConverter ac;
			double input = 2590000;
			double target = 1;
			AreaType type = AreaType::square_mile;
			double conversion_result = ac.fromSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" square meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert4046p86SquareMetersToAcres_Returns1) {
			AreaConverter ac;
			double input = 4046.86;
			double target = 1;
			AreaType type = AreaType::acre;
			double conversion_result = ac.fromSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" square meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert25p293SquareMetersToSquareRods_Returns1) {
			AreaConverter ac;
			double input = 25.293;
			double target = 1;
			AreaType type = AreaType::square_rod;
			double conversion_result = ac.fromSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" square meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert0p83613SquareMetersToSquareYards_Returns1) {
			AreaConverter ac;
			double input = 0.83613;
			double target = 1;
			AreaType type = AreaType::square_yard;
			double conversion_result = ac.fromSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" square meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert0p092903SquareMetersToSquareFoots_Returns1) {
			AreaConverter ac;
			double input = 0.092903;
			double target = 1;
			AreaType type = AreaType::square_foot;
			double conversion_result = ac.fromSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" square meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert0p00064516SquareMetersToSquareInches_Returns1) {
			AreaConverter ac;
			double input = 0.00064516;
			double target = 1;
			AreaType type = AreaType::square_inch;
			double conversion_result = ac.fromSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" square meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
	};
	TEST_CLASS(OldRussianSystemConversionTests) {
		TEST_METHOD(AreaConverter_Convert10930SquareMetersToDesyatina_Returns1) {
			AreaConverter ac;
			double input = 10930;
			double target = 1;
			AreaType type = AreaType::desyatina;
			double conversion_result = ac.fromSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" square meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert1093SquareMetersToKopna_Returns1) {
			AreaConverter ac;
			double input = 1093;
			double target = 1;
			AreaType type = AreaType::kopna;
			double conversion_result = ac.fromSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" square meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert4p552SquareMetersToSquareSajen_Returns1) {
			AreaConverter ac;
			double input = 4.552;
			double target = 1;
			AreaType type = AreaType::square_sajen;
			double conversion_result = ac.fromSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" square meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert0p5058SquareMetersToSquareArshin_Returns1) {
			AreaConverter ac;
			double input = 0.5058;
			double target = 1;
			AreaType type = AreaType::square_arshin;
			double conversion_result = ac.fromSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" square meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert0p001976SquareMetersToSquareVershok_Returns1) {
			AreaConverter ac;
			double input = 0.001976;
			double target = 1;
			AreaType type = AreaType::square_vershok;
			double conversion_result = ac.fromSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" square meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert1138000SquareMetersToSquareVersta_Returns1) {
			AreaConverter ac;
			double input = 1138000;
			double target = 1;
			AreaType type = AreaType::square_versta;
			double conversion_result = ac.fromSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input) + L" square meters" +
				+L" to type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
	};
}

namespace ConversionToSquareMetersTests {
	TEST_CLASS(MetricSystemConversionTests) {
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
		TEST_METHOD(AreaConverter_Convert1SquareCentimeterToSquareMeters_Returns0p0001) {
			AreaConverter ac;
			double input = 1;
			double target = 0.0001;
			AreaType type = AreaType::square_centimeter;
			double conversion_result = ac.toSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert1SquareMillimeterToSquareMeters_Returns0p000001) {
			AreaConverter ac;
			double input = 1;
			double target = 0.000001;
			AreaType type = AreaType::square_millimeter;
			double conversion_result = ac.toSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert1SquareDecimeterToSquareMeters_Returns0p01) {
			AreaConverter ac;
			double input = 1;
			double target = 0.01;
			AreaType type = AreaType::square_decimeter;
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
	TEST_CLASS(USASystemConversionTests) {
		TEST_METHOD(AreaConverter_Convert1SquareMileToSquareMeters_Returns2590000) {
			AreaConverter ac;
			double input = 1;
			double target = 2590000;
			AreaType type = AreaType::square_mile;
			double conversion_result = ac.toSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert1SquareRodToSquareMeters_Returns25p293) {
			AreaConverter ac;
			double input = 1;
			double target = 25.293;
			AreaType type = AreaType::square_rod;
			double conversion_result = ac.toSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert1SquareYardToSquareMeters_Returns0p83613) {
			AreaConverter ac;
			double input = 1;
			double target = 0.83613;
			AreaType type = AreaType::square_yard;
			double conversion_result = ac.toSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert1SquareFootToSquareMeters_Returns0p092903) {
			AreaConverter ac;
			double input = 1;
			double target = 0.092903;
			AreaType type = AreaType::square_foot;
			double conversion_result = ac.toSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert1SquareInchToSquareMeters_Returns0p00064516) {
			AreaConverter ac;
			double input = 1;
			double target = 0.00064516;
			AreaType type = AreaType::square_inch;
			double conversion_result = ac.toSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert1AcreToSquareMeters_Returns4046p86) {
			AreaConverter ac;
			double input = 1;
			double target = 4046.86;
			AreaType type = AreaType::acre;
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
	TEST_CLASS(OldRussianSystemConversionTests) {
		TEST_METHOD(AreaConverter_Convert1DesyatinaToSquareMeters_Returns10930) {
			AreaConverter ac;
			double input = 1;
			double target = 10930;
			AreaType type = AreaType::desyatina;
			double conversion_result = ac.toSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert1KopnaToSquareMeters_Returns1093) {
			AreaConverter ac;
			double input = 1;
			double target = 1093;
			AreaType type = AreaType::kopna;
			double conversion_result = ac.toSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert1SquareSajenToSquareMeters_Returns4p552) {
			AreaConverter ac;
			double input = 1;
			double target = 4.552;
			AreaType type = AreaType::square_sajen;
			double conversion_result = ac.toSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert1SquareArshinToSquareMeters_Returns0p5058) {
			AreaConverter ac;
			double input = 1;
			double target = 0.5058;
			AreaType type = AreaType::square_arshin;
			double conversion_result = ac.toSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert1SquareVershokToSquareMeters_Returns0p001976) {
			AreaConverter ac;
			double input = 1;
			double target = 0.001976;
			AreaType type = AreaType::square_vershok;
			double conversion_result = ac.toSquareMeters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(AreaConverter_Convert1SquareVerstaToSquareMeters_Returns1138000) {
			AreaConverter ac;
			double input = 1;
			double target = 1138000;
			AreaType type = AreaType::square_versta;
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

namespace ConversionToLitersTests {
	TEST_CLASS(MetricSystemConversionTests) {
		TEST_METHOD(VolumeConverter_Convert1CubicMeterToLiters_Returns1000) {
			VolumeConverter vc;
			double input = 1;
			double target = 1000;
			VolumeType type = VolumeType::cubic_meter;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1CubicCentieterToLiters_Returns0p001) {
			VolumeConverter vc;
			double input = 1;
			double target = 0.001;
			VolumeType type = VolumeType::cubic_centimeter;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1CubicMillimeterToLiters_Returns0p000001) {
			VolumeConverter vc;
			double input = 1;
			double target = 0.000001;
			VolumeType type = VolumeType::cubic_millimeter;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1CubicDecimeterToLiters_Returns1) {
			VolumeConverter vc;
			double input = 1;
			double target = 1;
			VolumeType type = VolumeType::cubic_decimeter;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
	};
	TEST_CLASS(USASystemConversionTests) {
		TEST_METHOD(VolumeConverter_Convert1FluidOunce1ToLiters_Returns0p02956) {
			VolumeConverter vc;
			double input = 1;
			double target = 0.02956;
			VolumeType type = VolumeType::fluid_ounce;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1FluidPintToLiters_Returns0p473) {
			VolumeConverter vc;
			double input = 1;
			double target = 0.473;
			VolumeType type = VolumeType::fluid_pint;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1FluidGallonToLiters_Returns3p785) {
			VolumeConverter vc;
			double input = 1;
			double target = 3.785;
			VolumeType type = VolumeType::fluid_gallon;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1FluidBarrelToLiters_Returns119p2) {
			VolumeConverter vc;
			double input = 1;
			double target = 119.2;
			VolumeType type = VolumeType::fluid_barrel;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1SolidPintToLiters_Returns0p55) {
			VolumeConverter vc;
			double input = 1;
			double target = 0.55;
			VolumeType type = VolumeType::solid_pint;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1SolidGallonToLiters_Returns4p405) {
			VolumeConverter vc;
			double input = 1;
			double target = 4.405;
			VolumeType type = VolumeType::solid_gallon;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1SolidBarrelToLiters_Returns115p6) {
			VolumeConverter vc;
			double input = 1;
			double target = 115.6;
			VolumeType type = VolumeType::solid_barrel;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
	};
	TEST_CLASS(OldRussianSystemConversionTests) {
		TEST_METHOD(VolumeConverter_Convert1BochkaToLiters_Returns491p96) {
			VolumeConverter vc;
			double input = 1;
			double target = 491.96;
			VolumeType type = VolumeType::cubic_meter;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1KorchagaToLiters_Returns24p59882) {
			VolumeConverter vc;
			double input = 1;
			double target = 24.59882;
			VolumeType type = VolumeType::cubic_meter;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1VedroToLiters_Returns12p29941) {
			VolumeConverter vc;
			double input = 1;
			double target = 12.29941;
			VolumeType type = VolumeType::vedro;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1ChetvertToLiters_Returns3p0748) {
			VolumeConverter vc;
			double input = 1;
			double target = 3.0748;
			VolumeType type = VolumeType::chetvert;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1OsmuhaToLiters_Returns1p5374) {
			VolumeConverter vc;
			double input = 1;
			double target = 1.5374;
			VolumeType type = VolumeType::osmuha;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1VineBottleToLiters_Returns0p7687) {
			VolumeConverter vc;
			double input = 1;
			double target = 0.7687;
			VolumeType type = VolumeType::vine_bottle;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1VodkaBottleToLiters_Returns0p6) {
			VolumeConverter vc;
			double input = 1;
			double target = 0.6;
			VolumeType type = VolumeType::vodka_bottle;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1StakanToLiters_Returns0p273) {
			VolumeConverter vc;
			double input = 1;
			double target = 0.273;
			VolumeType type = VolumeType::stakan;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1KadkaToLiters_Returns839p69) {
			VolumeConverter vc;
			double input = 1;
			double target = 839.69;
			VolumeType type = VolumeType::kadka;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1SolidChetvertToLiters_Returns209p9225) {
			VolumeConverter vc;
			double input = 1;
			double target = 209.9225;
			VolumeType type = VolumeType::solid_chetvert;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1OsminaToLiters_Returns104p96125) {
			VolumeConverter vc;
			double input = 1;
			double target = 104.96125;
			VolumeType type = VolumeType::osmina;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1ChetverikToLiters_Returns26p2387) {
			VolumeConverter vc;
			double input = 1;
			double target = 26.2387;
			VolumeType type = VolumeType::chetverik;
			double conversion_result = vc.toLiters(type, input);
			std::wstring msg = (
				L"Conversion result of " + std::to_wstring(input)
				+ L" of type " + std::to_wstring(type)
				+ L" should be equal to " + std::to_wstring(target)
				+ L"; got " + std::to_wstring(conversion_result)
				);
			Assert::IsTrue(abs(conversion_result - target) <= EPS, msg.c_str());
		}
		TEST_METHOD(VolumeConverter_Convert1GarnecToLiters_Returns3p2798) {
			VolumeConverter vc;
			double input = 1;
			double target = 3.2798;
			VolumeType type = VolumeType::garnec;
			double conversion_result = vc.toLiters(type, input);
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