#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution{
public:
	int lengthOfLongestSubstring(string s)
	{
		map<string, int> mapping;
		string substr;
		string::iterator p1, p2;
		p1 = s.begin();
		p2 = p1++;
		
		while (p2 != s.end())
		{	
			int i = s.find(*p2);
			if (p1 <= (s.begin() + i) && (s.begin() + i) < p2)
			{
				substr = string(p1, p2);
				p1 = p2;
				p2++;
				mapping[substr] = substr.size();
			}
			else
			{
				p2++;
				continue;
			}
		}
		if (p2 == s.end())
		{
			substr = string(p1, p2);
			mapping[substr] = substr.size();
		}
		
		map<string, int>::reverse_iterator iter = mapping.rbegin();
		int length = iter->second;
		cout << iter->first << endl;
		return length;
	}
};

int main()
{	
	Solution len_str;
	string str;
	str = "abcadbcdd";
	int len = 0;
	len = len_str.lengthOfLongestSubstring(str);
	cout << "The length of longestSubstring is:"
		<< len << endl;

	cout << "Now you can input a string to try: ";
	string s;
	if (cin >> s)
		len = len_str.lengthOfLongestSubstring(s);
	cout << "The length of longestSubstring of the input string is:"
		<< len << endl;

	getchar();
	return 0;
}