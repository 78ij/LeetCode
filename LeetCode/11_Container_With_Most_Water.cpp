#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int i = 0, j = height.size() - 1;
		int maxwater = 0, water = 0;
		int maxa, maxb;
		while (i != j) {
			water = (abs(i - j) * min(height[i], height[j]));
			if (maxwater < water) {
				maxwater = water;
				maxa = i;
				maxb = j;
			}
			if (height[i] < height[j])
				i++;
			else
				j--;
		}
		return maxwater;
	}
};

int main(int argc, char **argv) {
	Solution solution;
	int height;
	vector<int> heights;
	int res;
	res = solution.maxArea(heights);
	cout << res;
	system("pause");
}