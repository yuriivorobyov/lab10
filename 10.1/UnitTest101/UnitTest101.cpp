#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\User\Desktop\Політех\АТП\лаби\10 тема\10.1\10.1\10.1.cpp"

#define TESTING

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101

{
	TEST_CLASS(UnitTest101)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			bool functionResult = find();

			Assert::AreEqual(false, functionResult);
		}
	};
}


