/*
编辑距离：给定n个长度不超过10的字符串以及m次询问，每次询问给出一个字符串和一个操作次数上限。
         对于每次询问，请你求出给定的n个字符串中有多少个字符串可以在上限操作次数内经过操作变成询问给出的字符串。
         每个对字符串进行的单个字符的插入、删除或替换算作一次操作。
思路：同最短编辑距离思路一样，只不过这道题是求多个字符串的编辑距离，注意字符串的读取
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, m;
char str[N];
int dp[N][N];
char s[N][N];

int edit(char str1[], char str2[])
{
	// strlen()可以读取字符串的长度，即读到'\0'
	int n = strlen(str1 + 1) + 1;
	int m = strlen(str2 + 1) + 1;

	for(int i = 0;i <= n;i ++) dp[i][0] = i;
	for(int i = 0;i <= m;i ++) dp[0][i] = i;

	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
		{
			// 对应字符相等，无需操作，其操作数等于dp[i-1][j-1]
			if(str1[i] == str2[j]) dp[i][j] = dp[i - 1][j - 1];
			else 
			{
				// 取分别进行增删改操作的最小值
				dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
				dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i][j]);
			}
		}
	return dp[n][m];
}


int main()
{
	cin >> n >> m;
	for(int i = 0;i < n;i ++)
		scanf("%s", s[i] + 1);

	for(int i = 0;i < m;i ++)
	{
		scanf("%s", str + 1);
		int k;
		cin >> k;

		int cnt = 0;

		for(int j = 0;j < n;j ++)
		{
		  if(edit(s[j], str) <= k) cnt ++;
		}
		printf("%d\n",cnt );
	}
	return 0;
}