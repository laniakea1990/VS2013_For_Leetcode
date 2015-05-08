//本程序实现的子字符串中不含任何重复的字母。
//具体提交版本见onenote
#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
//#include<hash_map>

using namespace std;

class Solution{
public:
	int lengthOfLongestSubstring(string s)
	{
		if (s == "")
			return 0;
		map<int, string> mapping;
		string substr;
		string::iterator p1, p2;
		p1 = s.begin();
		p2 = p1 + 1;
		
		while (p2 != s.end())
		{	
			if (p1 <= find(p1, s.end(), *p2) && find(p1, s.end(), *p2) < p2)
			{
				substr=string(p1, p2);
				p1++;
				mapping[substr.size()] = substr;
			}
			else
			{
				p2++;
			}
		}
		if (p2 == s.end())
		{
			substr=string(p1, p2);
			mapping[substr.size()] = substr;
		}
		
		map<int, string>::reverse_iterator iter = mapping.rbegin();
		return iter->first;
	}
};

int main()
{	
	Solution len_str;
	string str;
	str = "abcadbcdd";
	//str = "abba";
	int len = 0;
	len = len_str.lengthOfLongestSubstring(str);
	cout << "The length of longestSubstring is:"
		<< len << endl;
	getchar();
	return 0;
}