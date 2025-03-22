#include "pch.h"
#include "CppUnitTest.h"
#include "../2.6/Triangle.h"
#include "../2.6/Triangle.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Triangle t(3, 4, 5);
			double area = t.getArea();
			Assert::AreEqual(6.0, area, 0.001, L"Area should be 6.0");
		}
	};
}
