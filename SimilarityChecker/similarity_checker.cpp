#include <vector>
#include <string>
#include <iostream>

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
		double length_score = 60.0;
		int string1_length = str1.length();
		int string2_length = str2.length();
		if (string1_length == string2_length) return length_score;


		if (string1_length > string2_length) {
			double gap = string1_length - string2_length;
			length_score = length_score * (1.0 - gap / string2_length);
		}
		else {
			double gap = str2.length() - str1.length();
			length_score = length_score * (1.0 - gap / string1_length);
		}
		return length_score;
	}
};