/*
POJ 2385-抓苹果
题意：有两棵树，每秒钟只有一个树掉下一个苹果，有头牛站在第一棵树下，限制它的最大移动次数，求它能接到的
      最多的苹果个数
算法：动态规划
思路：dp[i][j]代表前i秒移动j次最多能接到的苹果树，状态转移：dp[i][j] = max(dp[i - 1][j]，dp[i - 1][j - 1])
      表示下一秒的状态有前一秒移动或者不移动的最大值决定。
*/

#include <iostream>
#include <cstring>
using namespace std;

const int T = 1010, W = 40;

int dp[T][W];
int arr[T];

int main()
{
	int t, w;
	cin >> t >> w;
    for(int i = 1;i <= t;i ++) cin >> arr[i];

    for(int i = 1;i <= t;i ++)
    {
    	for(int j = 0;j <= w;j ++)
    	{
    		if(j == 0) dp[i][j] = dp[i - 1][j];
    		else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);

    		if(j % 2 + 1 == arr[i]) dp[i][j] ++;
    	}
    }

    int ans = dp[t][0];
    for(int i = 1;i <= w;i ++)
    	ans = max(ans, dp[t][i]);
    cout << ans << endl;
    return 0;
}