#include "pch.h"
#include "CppUnitTest.h"
#include "../Converter/Converter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
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

	TEST_CLASS(ConversionTests) {
	public:
		TEST_METHOD(LengthConverter_Convert1kmToMeters_Returns1000) 
		{
			LengthConverter lc;
			double meters = lc.toMeters("km", 1);
			Assert::IsTrue(meters == 1000);
		}
	};
}
