/*
最长公共子序列：求两个字符串的最长公共子序列
思路：动态规划，dp[i][j]表示字符串s1的前i个字符和字符串s2的前j个字符之间最长公共子序列的长度
复杂度：O(nm)
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, m;
char str1[N], str2[N];
int dp[N][N];

int main()
{
	cin >> n >> m;
	scanf("%s%s",str1 + 1, str2 + 1);

	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
		{
			if(str1[i] == str2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}

    printf("%d\n", dp[n][m]);
}