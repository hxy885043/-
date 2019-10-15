/*
背包问题求解决方案数
题意：N件物品，容量V，第i件物品的体积vi,价值wi,求总体积不超过背包容量的最大价值的最优方案数
算法：动态规划
思路：跟01背包思路相同，需要用cnt[]数组记录容量为i时的最优方案个数
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010,mod = 1e9 + 7;

int V[N], W[N];
int dp[N];
int cnt[N];

int main()
{
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; ++i)
	{
		int a, b;
		cin >> a >> b;
		V[i] = a;
		W[i] = b;
	}
	
	for(int i = 0;i <= v;i ++) cnt[i] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = v; j >= V[i]; --j)
		{
			int value = dp[j - V[i]] + W[i];
			if(dp[j] < value){
				dp[j] = value;
				cnt[j] = cnt[j - V[i]];
			}
			else if(dp[j] == value)
			{
				cnt[j] = (cnt[j] + cnt[j - V[i]]) % mod;
			}

		}
	}

	cout << cnt[v] << endl;
	return 0;
}
