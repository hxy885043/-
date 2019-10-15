/*
多重背包问题
题意：有N种物品和容量为Ｖ的背包，第ｉ种物品最多si件，每件体积是vi，价值是wi，求体积和不超过背包容量的最大价值
算法：动态规划
*/
// 同01背包问题类似，只需要加一个件数的循环即可
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110;

int V[N], W[N], S[N];
int dp[N];

int main()
{
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		V[i] = a;
		W[i] = b;
		S[i] = c;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = v; j >= 0; --j)
		{
			for (int k = 0; k <= S[i]; ++k)
			{
				if(j >= k * V[i]) dp[j] = max(dp[j], dp[j - k * V[i]] + k * W[i]);
			}
		}
	}

	cout << dp[v] << endl;
	return 0;
   
}


// 二进制优化算法
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010, M = 2010;

int V[N], W[N], S[N];
int dp[M];
int a[11010], b[11010];

int main()
{
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		V[i] = a;
		W[i] = b;
		S[i] = c;
	}
     // 原来的n件商物品转化为t件物品
    int t = 0;
	for(int i = 1;i <= n;i ++)
	{
		// 进行二进制拆分 将j转化为二进制后左移1位
		for(int j = 1;j < S[i];j <<= 1)
		{
			a[t] = j * V[i]; // 重新定义容量数组
			b[t ++] = j * W[i]; // 重新定义价值数组
			S[i] -= j;
		}
		if(S[i])
		{
			a[t] = S[i] * V[i];
			b[t ++] = S[i] * W[i];
		}
	}

	for (int i = 0; i < t; ++i)
	{
		for (int j = v; j >= a[i]; --j)
		{
			dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
		}
	}


	cout << dp[v] << endl;
	return 0;
}