#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct mdict {
	mdict(char _data, int _first, int _second) : data(_data), first(_first), second(_second) {}
	char data;
	int first = 0;
	int second = 0;
};

bool comp(mdict a, mdict b) {
	if (a.first != b.first)
		return a.first < b.first;
	else
		return a.second < b.second;
}
class Solution {
public:
	vector<mdict> dict;
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		bool state = 0;
		int unit = numRows + numRows - 2;
		int units = ((unit != 0) ? (s.length() / unit + 1) : 1);
		int rows = 0;
		int cols = 0;
		for (int i = 0; i < s.length(); i++) {
			dict.push_back(mdict(s[i], rows, cols));
			if (rows < numRows - 1 && state == 0) {
				rows++;
			}
			else if (rows == numRows - 1 && state == 0) {
				state = 1;
				cols++;
				rows--;
			}
			else if (state == 1 && rows > 0) {
				cols++;
				rows--;
			}
			else if (state == 1 && rows == 0) {
				state = 0;
				rows++;
			}
		}
		sort(dict.begin(), dict.end(), comp);
		string ret;
		for (int i = 0; i<dict.size(); i++) {
			ret.append(1, dict[i].data);
		}
		return ret;
	}
};
