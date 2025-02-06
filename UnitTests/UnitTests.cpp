#include "pch.h"
#include "CppUnitTest.h"

#include "../MathInt/MathInt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(MathIntTests)
	{
	public:
		TEST_METHOD(IsPrimeTest)
		{
			MathInt num = 7;
			Assert::IsTrue(num.isPrime());
			MathInt num2 = 4;
			Assert::IsFalse(num.isPrime());
		}
	};
}
