#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char* longestPalindrome(char* s) {
	const int maxn = 1100;
	char tmp[maxn << 1];
	int Len[maxn << 1];

	int i;
	int olen = strlen(s);
	tmp[0] = '@';
	for (i = 1; i <= 2 * olen; i += 2)
	{
		tmp[i] = '#';
		tmp[i + 1] = s[i / 2];
	}
	tmp[2 * olen + 1] = '#';
	tmp[2 * olen + 2] = '$';
	tmp[2 * olen + 3] = 0;
	int len = 2 * olen + 1;

	int mx = 0;
	int ans = 0;
	int po = 0;
	int flag;
	//char *substr = NULL;
	char substr[1100];
	int start, end;

	for (int i = 1; i <= len; i++)
	{
		if (mx > i)
		{
			Len[i] = (mx - i) < Len[2 * po - i] ? (mx - 1) : Len[2 * po - i];
		}
		else
			Len[i] = 1;
		while (tmp[i - Len[i]] == tmp[i + Len[i]])
			Len[i]++;
		if (Len[i] + i > mx)
		{
			mx = Len[i] + i;
			po = i;
		}
		if (Len[i] >= ans)
		{
			ans = Len[i];
			flag = i;
		}
	}

	start = flag - Len[flag] + 2;
	end = flag + Len[flag] - 2;
	for (int i = start, j = 0; i <= end; i += 2, j++)
		substr[j] = tmp[i];

	return substr;
}
int main()
{
	char text[1000];
	char *sub;
	/*strcpy_s(text, "babcbabcbaccba");
	sub = longestPalindrome(text);
	printf("the longestPalindrome is %s", sub);
*/
	/*char tt[10000] = "anugnxshgonmqydttcvmtsoaprxnhpmpovdolbidqiyqubirkvhwppcdyeouvgedccipsvnobrccbndzjdbgxkzdbcjsjjovnhpnbkurxqfupiprpbiwqdnwaqvjbqoaqzkqgdxkfczdkznqxvupdmnyiidqpnbvgjraszbvvztpapxmomnghfaywkzlrupvjpcvascgvstqmvuveiiixjmdofdwyvhgkydrnfuojhzulhobyhtsxmcovwmamjwljioevhafdlpjpmqstguqhrhvsdvinphejfbdvrvabthpyyphyqharjvzriosrdnwmaxtgriivdqlmugtagvsoylqfwhjpmjxcysfujdvcqovxabjdbvyvembfpahvyoybdhweikcgnzrdqlzusgoobysfmlzifwjzlazuepimhbgkrfimmemhayxeqxynewcnynmgyjcwrpqnayvxoebgyjusppfpsfeonfwnbsdonucaipoafavmlrrlplnnbsaghbawooabsjndqnvruuwvllpvvhuepmqtprgktnwxmflmmbifbbsfthbeafseqrgwnwjxkkcqgbucwusjdipxuekanzwimuizqynaxrvicyzjhulqjshtsqswehnozehmbsdmacciflcgsrlyhjukpvosptmsjfteoimtewkrivdllqiotvtrubgkfcacvgqzxjmhmmqlikrtfrurltgtcreafcgisjpvasiwmhcofqkcteudgjoqqmtucnwcocsoiqtfuoazxdayricnmwcg";
	sub = longestPalindrome(tt);
	printf("the longestPalindrome is %s", sub);*/

	strcpy_s(text, "forgeeksskeegfor");
	sub = longestPalindrome(text);
	printf("the longestPalindrome is %s", sub);

	//strcpy_s(text, "caba");
	//sub = longestPalindrome(text);
	//printf("the longestPalindrome is %s", sub);

	//strcpy_s(text, "abacdfgdcabba");
	//sub = longestPalindrome(text);
	//printf("the longestPalindrome is %s", sub);

	//strcpy_s(text, "abacdedcaba");
	//sub = longestPalindrome(text);
	//printf("the longestPalindrome is %s", sub);

	getchar();
	return 0;
}