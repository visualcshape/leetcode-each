#include "ZigZag.h"

#include <vector>

ZigZag::ZigZag() {}

string ZigZag::convert(string s, int numRows) {
	if (numRows == 1) {
		return s;
	}
	string result = "";
	vector<string>* rows = new vector<string>();
	for (int i = 0; i < numRows; i++) {
		rows->push_back("");
	}

	int at = 0, atRow = 0;
	int dir = 1; // 1 = inc, 0 = dec
	while(at < s.length()) {
		(*rows)[atRow] += s[at++];
		if (at >= numRows && ((atRow+1) % numRows == 0 || atRow - 1 < 0)) {
			dir = !dir;
		}
		dir ? atRow++ : atRow--;
	}

	for (int i = 0; i < numRows; i++) {
		result.append((*rows)[i]);
	}
	
	return result;
}
