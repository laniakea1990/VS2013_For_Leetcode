//#include<stdlib.h>
//#include<stdio.h>
//#include<math.h>
//#include<string.h>
//
//#define min(x,y) (x<y?x:y)
//#define max(x,y) (x>y?x:y)
//
//const int maxn = 1000;
////char text[maxn];
//char tmp[maxn << 1];
//int Len[maxn << 1];
//
//int INIT(char *st)
//{
//	int i;
//	int len = strlen(st);
//	tmp[0] = '@';
//
//	for (i = 1; i <= 2 * len; i += 2)
//	{
//		tmp[i] = '#';
//		tmp[i + 1] = st[i / 2];
//	}
//	tmp[2 * len + 1] = '#';
//	tmp[2 * len + 2] = '$';
//	tmp[2 * len + 3] = 0;
//	
//	printf("the convert string is %s\n", tmp);
//
//	return 2 * len + 1;
//}
//
//int MANACHER(char *st)
//{
//	int mx = 0;
//	int ans = 0;
//	int po = 0;
//	int len, flag;
//	len = INIT(st);	
//	char substr[50];
//	int start, end;
//
//	printf("the original string is %s\n", st);
//	printf("the string's length change to %d\n", len);
//
//	for (int i = 1; i <= len; i++)
//	{
//		if (mx > i)
//		{
//			Len[i] = min(mx - i, Len[2 * po - i]);
//		}
//		else
//			Len[i] = 1;
//		while (tmp[i - Len[i]] == tmp[i + Len[i]])
//			Len[i]++;
//		if (Len[i] + i > mx)
//		{
//			mx = Len[i] + i;
//			po = i;
//		}
//		if (Len[i] >= ans)
//		{
//			ans = Len[i];
//			flag = i;
//		}
//	}
//
//	start = flag - Len[flag] + 2;
//	end = flag + Len[flag] - 2;
//	for (int i = start, j = 0; i <= end; i += 2, j++)
//		substr[j] = tmp[i];
//
//	printf("The longest substr is %s\n", substr);
//	return 0;
//}
//
//int main()
//{
//	char text[1000];
//
//	strcpy_s(text, "babcbabcbaccba");
//	MANACHER(text);
//	
//	strcpy_s(text, "forgeeksskeegfor");
//	MANACHER(text);
//
//	strcpy_s(text, "caba");
//	MANACHER(text);
//
//	strcpy_s(text, "abacdfgdcabba");
//	MANACHER(text);
//
//	strcpy_s(text, "abacdedcaba");
//	MANACHER(text);
//
//	getchar();
//	return 0;
//}