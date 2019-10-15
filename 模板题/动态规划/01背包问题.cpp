/*
01背包问题：
题意：有N件物品和一个容量是V的背包，第i件体积为v，价值为w，每件物品只能使用一次，求不超过背包容量的最大价值
算法：动态规划
*/
// 二维数组
// dp[i][j]表是前i件物品在背包容量不超过j的最大价值，对于第i件物品，有放和不放两种选择
// 若选择不放，dp[i][j] = dp[i - 1][j]
// 若选择放，放的时候有要求，当前容量j需大于等于v[i]，才可以放，dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i])

#include <iostream>

using namespace std;

const int N = 1010;

int V[N], W[N];
int dp[N][N];

int main()
{
    int n, v;
    cin >> n >> v;
    for(int i = 1;i <= n;i ++)
    {
        cin >> V[i] >> W[i];
    }
    
    
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= v;j ++)
        {
            dp[i][j] = dp[i - 1][j];
            if(j >= V[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - V[i]] + W[i]);
        }
    }
    int res = 0;
    for(int i = 1;i <= v;i ++) res = max(res, dp[n][i]);
    cout << res << endl;
    return 0;
}

// 优化一维数组
// 有二维数组的状态转移方程可知，i至于前一个i的状态有关，因此可以用一维数组进行优化，用下一轮i的状态不断覆盖上一轮i的状态
#include <iostream>

using namespace std;

const int N = 1010;

int V[N], W[N];
int dp[N];

int main()
{
    int n, v;
    cin >> n >> v;
    for(int i = 1;i <= n;i ++)
    {
        cin >> V[i] >> W[i];
    }
    for(int i = 1;i <= n;i ++)
    {
        for(int j = v;j >= 1;j --)
        {
            if(j >= V[i]) dp[j] = max(dp[j], dp[j - V[i]] + W[i]);
        }
    }

    cout << dp[v] << endl;
    return 0;
}