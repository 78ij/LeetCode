#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

//no hashmap
//use map instead.
//slower.
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s == "") return 0;
		map<char, int> charmap;
		map<char, int>::iterator it;
		int front = 0, tail = 0;
		string window;
		//window = s.substr(front,tail);
		charmap.insert(pair<char, int>(s[0], 0));
		int maxlength = 1;
		while (tail != s.size() - 1) {
			tail++;
			it = charmap.find(s[tail]);
			if (it == charmap.end()) {
				charmap.insert(pair<char, int>(s[tail], tail));
				if (tail - front + 1 > maxlength)
					maxlength = tail - front + 1;
				continue;
			}
			else {
				int newfront = it->second;
				for (int i = front; i <= newfront; i++) {
					charmap.erase(s[i]);
				}
				front = newfront + 1;
				if (tail - front > maxlength + 1)
					maxlength = tail - front + 1;
				charmap.insert(pair<char, int>(s[tail], tail));
			}
		}
		return maxlength;
	}
};