/*
POJ 3280-最小花费回文串
题意：给定一个字符串，可以增加和删除字母，并给除其权重，求使其变成回文串的最小花费
算法：动态规划
思路：dp[i][j]代表将第i个到第j个的区间变成回文串的最小cost
     1)若s[i] = s[j],dp[i][j] = min(dp[i][j], dp[i + 1][j - 1])
     2)若第i + 1到j已是回文串，可以通过删除s[i]或者末尾添加s[i] dp[i][j] = min(dp[i + 1][j] + cost[s[i]], dp[i][j])
     3)若第i到j - 1已是回文串，可以通过删除s[j]或者开头添加s[j] dp[i][j] = min(dp[i][j - 1] + cost[s[j]], dp[i][j])
     由转移方程可知，i需要从末尾开始转移，j从i开始转移
*/

#include <iostream>
#include <cstring>
using namespace std;

const int M = 2010;

char s[M];
int cost[26];
int dp[M][M];

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0;i < m;i ++) cin >> s[i];
    
    for(int i = 0;i < n;i ++) {
    	char a;
    	int b, c;
    	cin >> a >> b >> c;
    	cost[a - 'a'] = min(b, c);
    }

    for(int i = m - 1;i >= 0;i --)
    {
    	for(int j = i;j < m;j ++)
    	{
    		if(s[i] == s[j]) dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
    		else{
    			dp[i][j] = min(dp[i][j], dp[i + 1][j] + cost[s[i] - 'a']);
    			dp[i][j] = min(dp[i][j], dp[i][j - 1] + cost[s[j] - 'a']);
    		}

    	}   	

    }

    cout << dp[0][m - 1] << endl;
    return 0;
}