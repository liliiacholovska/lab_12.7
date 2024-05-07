#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12.7/lab12.7.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

        TEST_METHOD(InsertSingleElement)
        {
            Elem* L = nullptr;
            Insert(L, 10);
            Assert::IsNotNull(L);
            Assert::AreEqual(10, L->info);
            Assert::IsTrue(L->link == L);  
        }

        TEST_METHOD(InsertMultipleElements)
        {
            Elem* L = nullptr;
            Insert(L, 1);
            Insert(L, 2);
            Insert(L, 3);
            Assert::AreEqual(1, L->info);
            Assert::AreEqual(2, L->link->info);
            Assert::AreEqual(3, L->link->link->info);
            Assert::IsTrue(L->link->link->link == L); 
        }
	};
}