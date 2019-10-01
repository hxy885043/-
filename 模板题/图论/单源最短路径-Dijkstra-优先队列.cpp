/*
Dijkstra算法：寻找两点之间的最短路径
适用条件：边权值为正 
思路：采用优先队列进行优化，可将寻找当前所有访问过点的最短距离用优先队列（即小根堆）进行实现
复杂度：O(mlogn) 使用稀疏图,即顶点数较多，边数较少，用邻接表实现
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1e5 + 10, M = 1e5 + 10;

// 第一个表示到起点的最短距离，第二个表示顶点编号
typedef pair<int, int> PII;

struct  Edge
{
	int u, v, w;	
};

// 邻接表的表示
vector<Edge> edges[N];

int n, m;
int dis[N];
bool visited[N];


int dijstra()
{
	// 定义一个小顶堆
	priority_queue<PII, vector<PII>, greater<PII> > q;
    memset(dis, 0x3f, sizeof dis);
    memset(visited, 0, sizeof visited);

	dis[1] = 0;
	q.push(PII(0, 1));
	while(!q.empty())
	{

		PII p = q.top();
		q.pop();

		int v = p.second;
		if(visited[v]) continue;
		visited[v] = true;
		// 遍历所有与v相连的边
		for(int i = 0;i < edges[v].size();i ++)
		{
			Edge e = edges[v][i];
			if(dis[e.v] > dis[v] + e.w)
			{
				dis[e.v] = dis[v] + e.w;
				q.push(PII(dis[e.v], e.v));
			}
		}

	}
	if(dis[n] == 0x3f3f3f3f) return -1;
	else return dis[n];
}

int main()
{
	cin >> n >> m;
	for(int i = 0;i < m;i ++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back({u, v, w});
	}
	cout << dijstra() << endl;
}