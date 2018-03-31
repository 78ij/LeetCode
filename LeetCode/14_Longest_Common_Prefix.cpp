#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return string();
		if (strs.size() == 1) return strs[0];
		sort(strs.begin(), strs.end(),
			[](string &a, string &b) {
			return a.size()< b.size();
		});
		string shortest = strs[0];
		//strs.erase(strs.begin());
		int tail = shortest.size();
		for (string str : strs) {
			while (str.substr(0, tail) != shortest.substr(0, tail) && tail > 0) {
				tail--;
			}
		}
		return shortest.substr(0, tail);
	}
};
