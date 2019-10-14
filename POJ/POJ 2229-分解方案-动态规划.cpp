/*
POJ 2229-分解方案
题意：将一个数n分解为2的次幂的和，求分解方案数
算法：动态规划
思路：若n时奇数，则它的分解方案数与n-1时的相同，只要n-1的方案数加上1即可;若是偶数，则分为两种情况，一种是
      n - 1的所有方案数加1，另一种是n/2的方案每个数都乘上2
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10, mod = 1e9;
int dp[N];
int main()
{
	int n;
	cin >> n;
    dp[0] = 1;
	for(int i = 1;i <= n;i ++)
	{
		if(i & 1) dp[i] = dp[i - 1];
		else dp[i] = (dp[i - 1] + dp[i / 2]) % mod;
	}
	printf("%d\n",dp[n] );
	return 0;

}