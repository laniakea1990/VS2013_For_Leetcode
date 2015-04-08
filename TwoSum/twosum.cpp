#include<map>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		map<int, int> smap;
		vector<int> result;
		for (int i = 0; i < numbers.size(); i++)
		{
			smap[numbers[i]] = i;
		}
		for (int i = 0; i < numbers.size(); i++)
		{
			int gap = target - numbers[i];
			if (smap.find(gap) != smap.end() && smap[gap] > i)
			{
				result.push_back(i + 1);
				result.push_back(smap[gap] + 1);
			}
		}
		return result;

	}
};

int main()
{
	int ia[4] = { 2, 7, 11, 15 };
	vector<int> numbers(ia, ia + 4);
	Solution sol;
	vector<int> result = sol.twoSum(numbers, 9);
	vector<int>::iterator iter = result.begin();
	while (iter != result.end())
	{
		cout << *iter << "  ";
		iter++;
	}
	getchar();
	return 0;
}