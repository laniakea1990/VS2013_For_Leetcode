#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<sstream>
using namespace std;

void reverseWords(string &s) {
	if (s == "")
		return;
	string &str_ori = s;
	istringstream stream(str_ori);
	stack<string>  stk_reverse;
	string word;

	while (stream >> word)
	{
		stk_reverse.push(word);
	}
	
	string str_1;
	
	while (!stk_reverse.empty())
	{
		str_1 += stk_reverse.top();
		if (stk_reverse.size() != 1)
			str_1 += " ";
		stk_reverse.pop();
	}
	str_ori.assign(str_1);

}


int main()
{
	string str = "the sky is blue.";
	//string str = "a";
	reverseWords(str);
	cout << str << endl;

	getchar();
	getchar();
}
