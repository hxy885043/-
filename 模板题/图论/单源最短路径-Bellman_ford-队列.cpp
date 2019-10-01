/*
Bellman_ford算法：求单源最短路径（无边数限制）
适用范围：带负权值的有向无向图，但不适用有负权的回路
思路：设立一个队列来存储需要优化的节点，优化时每次取出队首结点u，并且用u点当前的最短路径估计值对离开u点所指向的结点v进行松弛操作，
如果v点的最短路径估计值有所调整，且v点不在当前的队列中，就将v点放入队尾。这样不断从队列中取出结点来进行松弛操作，直至队列空为止
时间复杂度：O(m)
*/
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5 + 10, M = 1e5 + 10;

struct  Edge
{
	int v, w;
};
vector<Edge> edges[N];
int dis[N];
// 顶点是否在队列中
int visited[N];
int n, m;
int spfa()
{
	memset(dis, 0x3f, sizeof dis);
	memset(visited, 0, sizeof visited);
	dis[1] = 0;

	queue<int> q;
	q.push(1);
	visited[1] = 1;

	while(!q.empty())
	{
		int t = q.front();
		q.pop();
		visited[t] = 0;

		for(int i = 0;i < edges[t].size();i ++)
		{
			int v = edges[t][i].v;	
			int w = edges[t][i].w;
			if(dis[v] > dis[t] + w){
				dis[v] = dis[t] + w;
				if(!visited[v]) {q.push(v); visited[v] = 1;}
			}
		}
	}

	if(dis[n] == 0x3f3f3f3f) return -1;

	return dis[n];
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

	int res = spfa();
	if(res == -1) printf("impossible\n");
	else printf("%d\n",res );
}