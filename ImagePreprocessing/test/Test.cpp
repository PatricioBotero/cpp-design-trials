// Test.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

#include "gtest/gtest.h"

TEST(Dummy1, Dummy2) {
	EXPECT_EQ(1, 1);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}