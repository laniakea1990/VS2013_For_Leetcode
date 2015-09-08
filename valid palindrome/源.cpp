#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool isPalindrome(string s)
{
	if (s == "")
		return true;
	transform(s.begin(), s.end(), s.begin(), tolower);
	auto left = s.begin(), right = prev(s.end());
	while (left < right)
	{
		if (!isalnum(*left))
			++left;
		else if (!isalnum(*right))
			--right;
		else if (*left != *right)
			return false;
		else
		{
			left++;
			right--;
		}
	}
	return true;
}

int main()
{
	string str1 = "A man, a plan, a canal: Panama";
	string str2 = "race a car";
	bool res_str1 = isPalindrome(str1);
	bool res_str2 = isPalindrome(str2);

	cout << "res_str1:" << res_str1 << endl;
	cout << "res_str2:" << res_str2 << endl;

	getchar();
}