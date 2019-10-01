/*
Bellman_ford算法：求单源最短路径（边数限制）
适用范围：带负权值的有向无向图，但不适用有负权的回路
思路：对所有的边进行至多n - 1次的迭代，第k次迭代更新从起点到其余点至多为k条边的最短距离路径
时间复杂度：O(nm) 比Dijkstra效率要低，但是Dijkstra算法不支持带负权值的图
*/

#include <iostream>
#include <cstring>

using namespace std;
const int N = 510, M = 10010;

int n, m, k;

struct Edge
{
	int u, v, w;
}edges[M];

int dis[N];
int backup[N];

int bellman_ford()
{
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;

	// 共进行k次迭代，每一次迭代更新从起点到其余每个点最多经过k条边的最短路径长度
	for(int i = 0;i < k;i ++)
	{
		// 将前一轮迭代后得到的dis数组备份，若不备份，直接使用dis,则可能会出现一条边中dis[u]在之前已更新过,及dis[u]已更新为
		// 经过i + 1条边的最短路径长度，在进行与它相连点v的松弛操作时，dis[v]则会更新成经过最多经过i + 2条边之后的最短长度
		memcpy(backup, dis, sizeof dis);
		for(int j = 0;j < m;j ++)
		{
			int u = edges[j].u, v = edges[j].v, w = edges[j].w;
			if(backup[u] != 0x3f3f3f3f && dis[v] > backup[u] + w)
				dis[v] = backup[u] + w;
		}
	}

	if(dis[n] == 0x3f3f3f3f) return -1;
	else return dis[n];
}

int main()
{
	cin >> n >> m >> k;

	for(int i = 0;i < m;i ++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		edges[i] = {a, b, w};
	}

	int t = bellman_ford();
	if(t == -1) printf("impossible\n");
	else printf("%d\n",t );
	return 0;
}