/*
车的放置：
题意：给定一个N*M的方格，问棋盘上能放多少不能相互攻击的车
算法：二分图最大匹配
思路：根据象棋规则，一行一列只能有一个车，因此，可将行列看作两个不相交的子集，车的放置位置看作边
      便可用二分图的最大匹配算法
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 210;

int matrix[N][N];
int visited[N];
int match[N];
int n, m, t;

bool dfs(int x)
{
    for(int i = 1;i <= m;i ++)
    {
        if(!visited[i] && !matrix[x][i])
        {
            visited[i] = 1;
            if(match[i] == 0 || dfs(match[i]))
            {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{

    cin >> n >> m >> t;
    for(int i = 0;i < t;i ++)
    {
        int a, b;
        cin >> a >> b;
        matrix[a][b] = 1;
    }
    
    int res = 0;
    for(int i = 1;i <= n;i ++)
    {
        memset(visited, 0, sizeof visited);
        if(dfs(i)) res++;
    }
    cout << res << endl;
    return 0;
}