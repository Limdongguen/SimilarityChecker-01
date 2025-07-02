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
		int result = 0;
		result = getLengthScore(str1, str2) + getAlphaScore(str1, str2);
		return result;
	}

private:
	int getAlphaScore(const string& str1, const string& str2) {
		int total_count = 0;
		int same_count = 0;
		for (auto i = 'A'; i <= 'Z'; i++) {
			if ((str1.find(i) != string::npos) || (str2.find(i) != string::npos)) total_count++;
			if ((str1.find(i) != string::npos) && (str2.find(i) != string::npos)) same_count++;
		}
		return  (same_count / total_count) * 40.0;
	}

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