/*
最短编辑距离：两个字符串，求通过增删改三种方式把A变成B的最小编辑次数
思路：动态规划，dp[i][j]表示字符串str1的前i个字符变成字符串str2的前j个字符之间最小编辑次数
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
	cin >> n;
	scanf("%s",str1 + 1);
	cin >> m;
	scanf("%s",str2 + 1);

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

    printf("%d\n", dp[n][m]);
}