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
}
