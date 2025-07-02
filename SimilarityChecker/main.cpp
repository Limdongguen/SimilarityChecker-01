#include "gmock/gmock.h"
#include "similarity_checker.cpp"
#include <iostream>

TEST(TS, TC1) {
	string test_string1 = "ASD";
	string test_string2 = "DSA";
	SimilarityChecker checker;
	int length_score = checker.run(test_string1, test_string2);
	EXPECT_EQ(60, length_score);
}

TEST(TS, TC2) {
	string test_string1 = "A";
	string test_string2 = "BB";
	SimilarityChecker checker;
	int length_score = checker.run(test_string1, test_string2);
	EXPECT_EQ(0, length_score);
}

TEST(TS, TC3) {
	string test_string1 = "AAABB";
	string test_string2 = "BAA";
	SimilarityChecker checker;
	int length_score = checker.run(test_string1, test_string2);
	EXPECT_EQ(20, length_score);
}


TEST(TS, TC4) {
	string test_string1 = "AA";
	string test_string2 = "AAE";
	SimilarityChecker checker;
	int length_score = checker.run(test_string1, test_string2);
	EXPECT_EQ(30, length_score);
}

int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}