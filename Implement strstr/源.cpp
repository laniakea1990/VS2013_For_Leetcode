#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int strStr(string haystack, string needle)
{
	if (haystack == "" && needle == "")
		return 0;
	auto begin1 = haystack.begin(), end1 = haystack.end();
	auto begin2 = needle.begin(), end2 = needle.end();
	auto res = search(begin1, end1, begin2, end2);
	if (res == end1)
		return -1;
	int result = 0;
	auto iter = begin1;
	while (iter != end1)
	{
		if (iter != res)
		{
			iter++;
			result++;
		}
		else
			break;
	}
	return result;
}