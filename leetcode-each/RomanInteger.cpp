#include "RomanInteger.h"
#include <unordered_map>

using namespace std;

RomanInteger::RomanInteger() {
}

int RomanInteger::romanToInt(string s) {
	unordered_map<string, int> romanIntegerMap = {
		{"I", 1},
		{"IV", 4},
		{"V", 5},
		{"IX", 9},
		{"X", 10},
		{"XL", 40},
		{"L", 50},
		{"XC", 90},
		{"C", 100},
		{"CD", 400},
		{"D", 500},
		{"CM", 900},
		{"M", 1000}
	};

	int result = 0;
	for (int i = 0, skipNext = 0; i < s.length(); skipNext == 1?i+=2:i++, skipNext=0) {
		const char currentChar[2] = { s[i], '\0' };
		char twoCurrentChar[3] = { NULL, NULL, '\0' };
		if (i + 1 < s.length()) {
			twoCurrentChar[0] = currentChar[0];
			twoCurrentChar[1] = s[i + 1];
			unordered_map<string, int>::const_iterator foundItr = romanIntegerMap.find(twoCurrentChar);
			if (foundItr != romanIntegerMap.end()) {
				result += foundItr->second;
				skipNext = 1;
				continue;
			}
		}

		result += romanIntegerMap[currentChar];
	}

	return result;
}
