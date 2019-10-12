/*
POJ 3259-虫洞
题意：农夫约翰有F个农场，每个农场有N块地，每块地有M条路（双向）以及W条虫洞（单向），即经过这一条路之后，可以让你的
时间倒回t,问能否从某一个点出发，回到起始点，且能看到出发前的自己
思路：将虫洞这条路看成时负权路，那么问题可转化为只要图中存在负权回路（即回路上的权值之和为负值），那么从这个环上的
任意一点出发，即可以回到过去的时间点。
算法：采用Bellman_ford最短路径算法，在进行n-1次迭代更新结束后，若存在负权环，则最短路径还可以一直更新下去，只要看
在n-1次迭代之后，再次对每条边进行遍历，若还可以进行更新最短路径，则说明存在负权环
*/

#include <iostream>
#include <cstring>

using namespace std;
const int N = 510, M = 5250;

int n, m, w;
struct Edge
{
	int u, v, t;
}edges[M];

int d[N];
int cnt = 0;

bool bellman_ford()
{
	memset(d, 0x3f, sizeof d);
	d[1] = 0;

	for(int i = 0;i < n;i ++)
	{
		for(int j = 0;j < cnt;j ++)
		{
			int u = edges[j].u, v = edges[j].v, t = edges[j].t;
			d[v] = min(d[v], d[u] + t);

		}
	}
	int flag = 0;

	for(int j = 0;j < cnt;j ++)
	{
		int u = edges[j].u, v = edges[j].v, t = edges[j].t;
		if(d[v] > d[u] + t)
		{
			flag = 1;
			break;
		}
	}

	return flag;

}


int main()
{
	int f;
	cin >> f;
	while(f --)
	{
		cin >> n >> m >> w;
		cnt = 0;
		int u, v, t;
		for(int i = 0;i < m;i ++)
		{			
			cin >> u  >> v >> t;
			edges[cnt].u = u;
			edges[cnt].v = v;
			edges[cnt].t = t;
			cnt ++;
            edges[cnt].v = u;
			edges[cnt].u = v;
			edges[cnt].t = t;
			cnt ++;
		}

		for(int i = 0;i < w;i ++)
		{
			cin >> u >> v >> t;
			edges[cnt].u = u;
			edges[cnt].v = v;
			edges[cnt].t = -t;
			cnt ++;
		}
    		
    	bool res = bellman_ford();
    	printf("%s\n", res?"YES":"NO");

	}
	return 0;
}