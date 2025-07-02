#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>

using std::vector;
using std::string;

class SimilarityChecker {
public:
	int run(const string& str1, const string& str2) {
		return getLengthScore(str1, str2);
	}

private:
	int getLengthScore(const string& str1, const string& str2)
	{
		int length_score = 60;
		int max_length = std::max(str1.length(), str2.length());
		int min_length = std::min(str1.length(), str2.length());
		double gap = std::abs(max_length - min_length);

		length_score = length_score * (1.0 - gap / min_length);

		if (length_score < 0) length_score = 0;

		return length_score;
	}
};