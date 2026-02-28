#include "pch.h"
#include "CppUnitTest.h"
#include "../Converter/Converter.cpp"

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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result - target <= 0.0000001, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
		}
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
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
			Assert::IsTrue(conversion_result == target, msg.c_str());
		}
	};
}