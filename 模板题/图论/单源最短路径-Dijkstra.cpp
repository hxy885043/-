/*
Dijkstra算法：寻找两点之间的最短路径
适用范围：边权值为正 
思路：贪心思维，进行n-1迭代，每次迭代确定一个最短路径上的点，该点是从所有未访问点中距离起始点最近的一个，并更新与该点相连的所有点的距离值
复杂度：O(n^2) 使用稠密图,即顶点数较少，用邻接矩阵实现
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, M = 1e5 + 10;

int n, m;
int matrix[N][N];
int dis[N];
bool visited[N];

int dijkstra()
{
	memset(visited, 0, sizeof visited);
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;

	// 进行n-1次迭代，每次迭代选择一个点更新到最短路径中
	for(int i = 1;i <= n - 1;i ++)
	{
		// 从所有未访问的点中找到距离起点最近的一个点
		int k = 0;
		int min = 0x3f3f3f3f;
		for(int j = 1;j <= n;j ++)
		{
			if(!visited[j] && dis[j] < min)
			{
				min = dis[j];
				k = j;
			}
		}

		// 找到最近的点k，并标记已访问
		visited[k] = 1;

		// 以k为基准更新所有与K相邻的点的dis值
		for(int j = 1;j <= n;j ++)
		{
			dis[j] = min(dis[j], dis[k] + matrix[k][j]);
		}
	}

	if(dis[n] == 0x3f3f3f3f) return -1;
	else return dis[n];
}


int main()
{
	cin >> n >> m;
	memset(matrix, 0x3f, sizeof(matrix));
	for(int i = 0;i < m;i ++)
	{
		int x, y, z;
		cin >> x >> ｙ >> z;
		matrix[x][y] = min(matrix[x][y], z);
	}
	cout << dijkstra() << endl;
}