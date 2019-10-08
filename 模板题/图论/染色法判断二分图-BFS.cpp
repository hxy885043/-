/*
染色法判断二分图：
二分图定义:顶点集v可分割位两个互不相交的子集，子集内部点没有边相连，两个子集之间的点有边相连
算法：BFS
思路：先将一个点染色，再将与这个点相连的所有边染不同色，以队列的形式读取，若再染色过程中发现两顶点颜色相同，则可判断不是二分图。
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int N =1e5 + 10;

vector<int> edges[N];

int color[N];
queue<int> q;

int main()
{
    int n, m;
    cin >> n >> m;
    
    for(int i = 0;i < m;i ++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    memset(color, -1, sizeof color);
    color[1] = 1;
    q.push(1);
    
    while(!q.empty())
    {
        int t = q.front();
        int c = color[t];
        q.pop();
        
        for(int i = 0;i < edges[t].size();i ++)
        {
            int temp = edges[t][i];
            if(color[temp] == -1)
            {
                color[temp] = ~c;
                q.push(temp);
            }
            else if(color[temp] == c)
            {
                printf("No\n");
                return 0;
            }
        }
    }
    
    printf("Yes\n");
    return 0;
    
}