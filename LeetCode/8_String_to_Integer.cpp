#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	string trimspace(string str) {
		string ret;
		string ret2;
		bool a = true;
		for (int i = 0; i < str.size(); i++) {
			if (a && str[i] == ' ') continue;
			else if (a && str[i] != ' ') {
				a = false;
				ret += str[i];
			}
			else {
				ret += str[i];
			}
		}
		a = true;
		for (int i = ret.size() - 1; i >= 0; i--) {
			if (a && ret[i] == ' ') continue;
			else if (a && ret[i] != ' ') {
				a = false;
				ret2 += ret[i];
			}
			else {
				ret2 += ret[i];
			}
		}
		reverse(ret2.begin(), ret2.end());
		return ret2;
	}

	string preprocess(string str) {
		str = trimspace(str);
		string ret;
		bool isvalid = true;
		for (int i = 0; i < str.size(); i++) {
			if (i == 0 && !((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-')) {
				return "";
			}
			else if (isvalid && ((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-')) {
				ret.push_back(str[i]);
				continue;
			}
			else if (isvalid && !((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-')) {
				break;
			}
		}
		return ret;
	}


	int ctoi(const char &a) {
		return (int)a - 48;
	}

	int myAtoi(string str) {
		string nospace = trimspace(str);
		str = preprocess(str);
		bool isminus = false;
		bool isstart = true;
		int bit = 0;
		double mul = 1;
		int size = str.size();
		if (nospace[0] == '-') isminus = true;
		if (str == "") return 0;
		if (nospace[0] == '+' && nospace[1] == '-') return 0;
		if (nospace[0] == '-' && nospace[1] == '+') return 0;
		if (nospace[0] == '-' && nospace[1] == '-') return 0;
		if (nospace[0] == '+' && nospace[1] == '+') return 0;
		for (int j = size - 1; j >= 0; j--) {
			if (str[j] == '-' || str[j] == '+') break;
			if (isstart && str[j] == '0') {
				mul *= 10;
				continue;
			}
			if (isstart && str[j] != '0') {
				isstart = false;
				double a = bit;
				a += (double)ctoi(str[j]) * (double)mul;
				if (a > INT_MAX) {
					if (isminus) return -INT_MAX;
					else return INT_MAX;
				}
				bit += ctoi(str[j]) * mul;
				mul *= 10;
				continue;
			}
			if (!isstart) {
				double a = bit;
				a += (double)ctoi(str[j]) * (double)mul;
				if (a > INT_MAX) {
					if (isminus) return -INT_MAX - 1;
					else return INT_MAX;
				}
				bit += ctoi(str[j]) * mul;
				mul *= 10;
			}
		}
		return isminus ? -bit : bit;
	}
};
