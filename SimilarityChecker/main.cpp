#include "gmock/gmock.h"
#include "similarity_checker.cpp"
#include <iostream>

class SimilarityCheckerFixture : public testing::Test {
public:
	SimilarityChecker checker;
	void run(int expected, string test_string1, string test_string2) {
		auto score = checker.run(test_string1, test_string2);
		EXPECT_EQ(expected, score);
	}
};

TEST_F(SimilarityCheckerFixture, TC1) {
	run(60, "ASD", "DSA");
}

TEST_F(SimilarityCheckerFixture, TC2) {
	run(0, "A", "DSA");
}

TEST_F(SimilarityCheckerFixture, TC3) {
	run(20, "ASDSF", "DSA");
}


TEST_F(SimilarityCheckerFixture, TC4) {
	run(30, "AA", "AAE");
}

int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}