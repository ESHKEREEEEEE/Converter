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
		TEST_METHOD(AreaConverterClassCreation) {
			AreaConverter* ac = new AreaConverter();
			Assert::IsNotNull(ac);
		}
	};
}
