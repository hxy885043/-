/*
Bellman_ford算法：求是否存在负环
思路：用一个数组来存储每个节点最短路径的的边数，在更新dis时判断边数是否大于n - 1，如果大于，则判断存在负环
时间复杂度：O(m)
*/
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int N = 2010, M = 10010;

struct  Edge
{
	int v, w;
};

vector<Edge> edges[N];


int n, m;
int visited[N];
int dis[N];
// 到该点的最短路径的边数
int cnt[N];

int bellman_ford()
{
	memset(dis, 0x3f, sizeof dis);
	memset(cnt, 0, sizeof cnt);
	queue<int> q;
	
	// 需要把每个节点都入队，因为可能存在不连通的情况
	for(int i = 1;i <= n;i ++)
	{
	    q.push(i);
	    visited[i] = 1;
	    dis[i] = 0;
	}
	while(!q.empty())
	{
		int t = q.front();
		q.pop();
		visited[t] = 0;

		for(int i = 0;i < edges[t].size();i ++)
		{
			Edge temp = edges[t][i];
			int v = temp.v, w = temp.w;
			if(dis[v] > dis[t] + w)
			{
				dis[v] = dis[t] + w;
				cnt[v] = cnt[t] + 1;

                // 若某个点最短路径的边数大于n - 1说明存在负环
				if(cnt[v] > n - 1) return true;
				if(!visited[v])
				{
					q.push(v);
					visited[v] = 1;
				}

			}
		}
	}
	return false;
}

int main()
{
	cin >> n >> m;
	for(int i = 0;i < m;i ++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back({v, w});
	}

	if(bellman_ford() == 0) printf("No\n");
	else printf("Yes\n");
}