/*
POJ 3616-牛奶时间
题意：给定多个时间区间及其价值，求每个时间区间需相隔r的最大价值为多少
算法：动态规划
思路：将区间按终点进行排序，dp[i]记录以i为结尾的区间最大价值，dp[i] = max(dp[i], dp[j] + intervals[i].e)
      j在0-i-1之间，即在求第i个状态的时候，需遍历之间的状态加上当前区间的价值的最大值
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10, M = 1010;

struct node 
{
	int a, b, e;
	bool operator < (const node &c)const{
		return b < c.b;
	}
	
}intervals[M];

int dp[M];

int main()
{
	int n, m, r;
	cin >> n >> m >> r;
	for(int i = 0;i < m;i ++)
	{
		int a, b, e;
		cin >> a >> b >> e;
		intervals[i].a = a;
		intervals[i].b = b + r;
		intervals[i].e = e;
	}

	sort(intervals, intervals + m);


	for(int i = 0;i < m;i ++){
		dp[i] = intervals[i].e;
		for(int j = 0;j < i;j ++)
		{
			if(intervals[j].b <= intervals[i].a)
				dp[i] = max(dp[i], dp[j] + intervals[i].e);
		}
	}

	int ans = dp[0];
	for(int i = 0;i < m;i ++)
	{
		ans = max(dp[i], ans);
	}
	cout << ans << endl;
	return 0;

}