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
		}
		TEST_METHOD(MassConverterClassCreation)
		{
			MassConverter* mc = new MassConverter();
			Assert::IsNotNull(mc);
		}
		TEST_METHOD(VolumeConverterClassCreation)
		{
			VolumeConverter* vc = new VolumeConverter();
			Assert::IsNotNull(vc);
		}
	};
}

namespace ConversionTests
{
	TEST_CLASS(MeterSystemConversionTests) {
	public:
		TEST_METHOD(LengthConverter_Convert1kmToMeters_Returns1000) 
		{
			LengthConverter lc;
			double meters = lc.toMeters(LengthType::kilometers, 1);
			Assert::IsTrue(meters == 1000);
		}
		TEST_METHOD(LengthConverter_Convert10kmToMeters_Returns10000)
		{
			LengthConverter lc;
			double meters = lc.toMeters(LengthType::kilometers, 10);
			Assert::IsTrue(meters == 10000);
		}		
	};
	TEST_CLASS(OldRussianSystemConversionTests) {
	public:
		TEST_METHOD(LengthConverter_Convert1VershokToMeters_Returns0045) {
			LengthConverter lc;
			double meters = lc.toMeters(LengthType::vershok, 1);
			Assert::IsTrue(meters == 0.045);
		}
	};
}
