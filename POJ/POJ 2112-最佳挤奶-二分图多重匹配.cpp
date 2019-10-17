/*
POJ 2112-最佳挤奶
题意：有K个挤奶机器，C头牛，给出K+C个点到其余每个点的距离，每台机器只能服务M头牛，求在所有牛都被服务的情况下，
     使得牛到机器的最远距离最小化。
算法：二分+二分图多重匹配+最短路
思路：1) 对距离进行二分，判断最远距离为mid的情况下，能够满足所有牛被服务
     2) 判断所有牛是否能被服务，注意到挤奶机器和牛是一对多的关系，因此可以采用二分图多重匹配来判断是否能满足
     3）如何将mid距离应用到2)的判断中去？先将所有点到点的最短距离求出来，因为题目是是要距离最小化，然后将所有
        小于等于mid的边挑选出来，作为二分图的邻接边来进行判断
     4) 若不能满足所有牛都被匹配，说明边太小了，将边范围调整大大范围，若能满足，可以在小于等于mid的范围内继续寻找
注意：最大取值范围的设定
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 250, M = 460;
const int INF = 0x3f3f3f3f;

int matrix[N][N];
int e[N][M];

int match[M];
int visited[M];
int k, c, m;

void floyd()
{
	for (int o = 0; o < k + c; ++o)
	{
		for(int i = 0; i < k + c; ++i)
		{
			for (int j = 0; j < k + c; ++j)
			{
				matrix[i][j] = min(matrix[i][j], matrix[i][o] + matrix[o][j]);
			}
		}
	}

}

bool dfs(int x)
{
	for(int i = 0;i < k * m;i ++)
	{
		if(e[x][i] && !visited[i])
		{
			visited[i] = 1;
			if(match[i] == -1 || dfs(match[i]))
			{
				match[i] = x;
				return true;
			}
		}
	}
	return false;
}

bool check(int x)
{
	memset(e, 0, sizeof e);
	memset(match, -1, sizeof match);
	for (int i = 0; i < k; ++i)
	{
		for (int j = k; j < k + c; ++j)
		{
			if(matrix[i][j] <= x) 
			{
				for (int o = i * m; o < (i + 1) * m; ++o)
				{
					e[j - k][o] = 1;
				}
			}
		}
	}
	
	for(int i = 0;i < c;i ++)
	{
		memset(visited, 0, sizeof visited);
		if(!dfs(i)) return false;
	}
	return true;
}



int main()
{

	cin >> k >> c >> m;
	for(int i = 0;i < k + c;i ++)
	{
		for (int j = 0; j < k + c; j++)
		{
			cin >> matrix[i][j];
			if(matrix[i][j] == 0) matrix[i][j] = INF;
		}
	}

	floyd();
    int left = 0, right = 0;
	for (int i = 0; i < k + c; ++i)
	{
		for (int j = 0; j < k + c; ++j)
		{
			right = max(right, matrix[i][j]);
		}
	}

	while(left < right)
	{
		int mid = (left + right) / 2;
		if(check(mid)) right = mid;
		else left = mid + 1;
	}

	cout << left << endl;

}

