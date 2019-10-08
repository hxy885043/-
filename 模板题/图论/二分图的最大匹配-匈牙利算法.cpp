/*
二分图的最大匹配：
定义：给定一个二分图G，在G的一个子图M中， M的边集{E}中的任意两条边都不交汇于同一个结点，则称M是一个匹配，求其边数最大的子图
思路：给定二分图的a,b两个子集，遍历a子集中的每个顶点，找到b子集中与其对应的顶点，用match数组标记b集合中每个顶点所连接的顶点
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 510;

vector<int> edges[N];
int visited[N];
int match[N];

bool dfs(int x)
{
    for(int i = 0;i < edges[x].size();i ++)
    {
        int temp = edges[x][i];
        if(!visited[temp])
        {
            visited[temp] = 1;
            // 若该顶点未匹配或者匹配过但是与其匹配的顶点可以找到另一个顶点与其匹配，那么可以将x匹配给它
            if(match[temp] == -1 || dfs(match[temp]))
            {
                match[temp] = x;
                return true;
            }
        }
    }
    return false;
}


int main()
{
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    
    for(int i = 0;i < m;i ++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
    }
    memset(match, -1, sizeof match);
    int res = 0;

    for(int i = 1;i <= n1;i ++)
    {
        memset(visited, 0, sizeof visited);
        if(dfs(i)) res ++;
    }
    
    printf("%d\n",res);
}