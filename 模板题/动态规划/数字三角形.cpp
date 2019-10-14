/*
数字三角形：
题意：给定一个数字三角形，从顶部出发，在每一结点可以选择移动至其左下方的结点或移动至其右下方的结点，一直走到底层，
要求找出一条路径，使路径上的数字的和最大。
算法：动态规划
思路：dp[i]表示走到第i个数的路径最大值，状态时层层更新

*/
#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int dp[N];
int temp[N];

int main()
{
	int n;
	cin >> n;
	int res = -INF;
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= i;j ++){
			cin >> temp[j];
		}
		
		for(int j = i;j >= 1;j --)
		{
		    if(j == 1) dp[j] = dp[j] + temp[j];
		    else if(j == i) dp[j] = dp[j - 1] +temp[j];
		    else dp[j] = max(dp[j - 1], dp[j]) + temp[j];
		    if(i == n) res = max(res, dp[j]);
		}
		
	}

	printf("%d\n", res);
}