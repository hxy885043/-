/*
完全背包问题:
题意：有N中物品和容量是V的背包，第i种物品的体积是vi,价值是wi,每种物品可无限次使用，求不超过容量的最大价值
算法：动态规划
思路：dp[i]表示不超过v的最大背包价值，与01背包不同的是，可以无限次加入物品，我们只需要对j的遍历顺序做一个改变即可
      也就是说我们限制只用上一轮的状态。
*/
#include <iostream>
using namespace std;

const int N = 1010;

int V[N], W[N];
int dp[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) cin >> V[i] >> W[i];
    
    for(int i = 1;i <= n;i ++)
    {
        for(int j = V[i];j <= m;j ++)
        {
            dp[j] = max(dp[j], dp[j - V[i]] + W[i]);
        }
    }
    
    cout << dp[m] << endl;
    return 0;
}