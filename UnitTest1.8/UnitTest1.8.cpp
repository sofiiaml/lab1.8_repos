#include "pch.h"
#include "CppUnitTest.h"
#include "../1.8/Account.h"
#include "../1.8/Account.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest18
{
	TEST_CLASS(UnitTest18)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Account a;
			Account::Date d;
			d.Init("2024.05.05");
			a.Init("a", "123", d, 15, 12000);
			a.withdraw(10000);
			double result = 2000;
			Assert::AreEqual(result, a.getMoney());

		}
	};
}
