#include "pch.h"
#include "CppUnitTest.h"
#include "../Converter/Converter.cpp"

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
			delete lc;
		}
		TEST_METHOD(MassConverterClassCreation)
		{
			MassConverter* mc = new MassConverter();
			Assert::IsNotNull(mc);
			delete mc;
		}
		TEST_METHOD(VolumeConverterClassCreation)
		{
			VolumeConverter* vc = new VolumeConverter();
			Assert::IsNotNull(vc);
			delete vc;
		}
		TEST_METHOD(AreaConverterClassCreation)
		{
			AreaConverter* ac = new AreaConverter();
			Assert::IsNotNull(ac);
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
			double meters = lc.toMeters(LengthType::kilometers, 1);
			Assert::IsTrue(meters == 1000);
		}
		TEST_METHOD(LengthConverter_Convert10KilometersToMeters_Returns10000)
		{
			LengthConverter lc;
			double meters = lc.toMeters(LengthType::kilometers, 10);
			Assert::IsTrue(meters == 10000);
		}		
	};

	TEST_CLASS(OldRussianSystemConversionTests) {
	public:
		TEST_METHOD(LengthConverter_Convert1VershokToMeters_Returns0d045) {
			LengthConverter lc;
			double meters = lc.toMeters(LengthType::vershok, 1);
			Assert::IsTrue(meters == 0.045);
		}
		TEST_METHOD(LengthConverter_Convert1PyadToMeters_Returns0d18) {
			LengthConverter lc;
			double meters = lc.toMeters(LengthType::pyad, 1);
			Assert::IsTrue(meters == 0.18);
		}
		TEST_METHOD(LengthConverter_Convert1LokotToMeters_Returns0d48) {
			LengthConverter lc;
			double meters = lc.toMeters(LengthType::lokot, 1);
			Assert::IsTrue(meters == 0.48);
		}
		TEST_METHOD(LengthConverter_Convert1ArshinToMeters_Returns0d72) {
			LengthConverter lc;
			double meters = lc.toMeters(LengthType::arshin, 1);
			Assert::IsTrue(meters == 0.72);
		}
		TEST_METHOD(LengthConverter_Convert1SajenToMeters_Returns2d16) {
			LengthConverter lc;
			double meters = lc.toMeters(LengthType::sajen, 1);
			Assert::IsTrue(meters == 2.16);
		}
		TEST_METHOD(LengthConverter_Convert1VerstaToMeters_Returns2160) {
			LengthConverter lc;
			double meters = lc.toMeters(LengthType::versta, 1);
			Assert::IsTrue(meters == 2160);
		}
	};
}

namespace ConversionFromMetersTests
{
	TEST_CLASS(MetricSystemConversionTests) {
	public:
		TEST_METHOD(LengthConverter_Convert1MeterToKilometers_Returns0d001) {
			LengthConverter lc;
			double kilometers = lc.fromMeters(LengthType::kilometers, 1);
			Assert::IsTrue(kilometers == 0.001);
		}
		TEST_METHOD(LengthConverter_Convert10MetersToKilometers_Returns0d01) {
			LengthConverter lc;
			double kilometers = lc.fromMeters(LengthType::kilometers, 1);
			Assert::IsTrue(kilometers == 0.001);
		}
	};

	TEST_CLASS(OldRussianSystemConversionTests) {
	public:
		TEST_METHOD(LengthConverter_Convert9MetersToVershok_Returns200) {
			LengthConverter lc;
			double vershok = lc.fromMeters(LengthType::vershok, 9);
			Assert::IsTrue(vershok == 200);
		}
		TEST_METHOD(LengthConverter_Convert4d5MetersToPyad_Returns25) {
			LengthConverter lc;
			double pyad = lc.fromMeters(LengthType::pyad, 4.5);
			Assert::IsTrue(pyad == 25);
		}
		TEST_METHOD(LengthConverter_Convert3MetersToLokot_Returns6d25) {
			LengthConverter lc;
			double lokot = lc.fromMeters(LengthType::lokot, 3);
			Assert::IsTrue(lokot == 6.25);
		}
		TEST_METHOD(LengthConverter_Convert9MetersToArshin_Returns12d5) {
			LengthConverter lc;
			double arshin = lc.fromMeters(LengthType::arshin, 9);
			Assert::IsTrue(arshin == 12.5);
		}
		TEST_METHOD(LengthConverter_Convert2d16MetersToSajen_Returns1) {
			LengthConverter lc;
			double sajen = lc.fromMeters(LengthType::sajen, 2.16);
			Assert::IsTrue(sajen == 1);
		}
		TEST_METHOD(LengthConverter_Convert2160MetersToVersta_Returns1) {
			LengthConverter lc;
			double versta = lc.fromMeters(LengthType::versta, 2160);
			Assert::IsTrue(versta == 1);
		}
	};
}
