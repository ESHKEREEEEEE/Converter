#include "pch.h"
#include "CppUnitTest.h"
#include "../Converter/Converter.cpp"

#define EPS 0.0000001

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
	};
}
