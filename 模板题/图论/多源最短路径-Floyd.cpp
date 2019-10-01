/*
Floyd算法：求多源最短路径
适用范围：含负权值的图，不包括有负权回路的图
思路：动态规划的思维，对于i,j两个点，可以通过中转点k从i走到j,也可以直接从i走到j,比较这两种方式的最小值
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 210, M = 20010, INF = 0x3f3f3f3f;

int n, m, k;
int d[N][N];

void floyd()
{
	for(int k = 1;k <= n;k ++)
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= n;j ++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}


int main()
{
	cin >> n >> m >> k;
	// 初始化数组
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= n;j ++)
		{
			if(i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}

    while(m --)
    {
    	int a, b, c;
    	cin >> a >> b >> c;
    	d[a][b] = min(d[a][b], c);
    }

    floyd();

    while(k --)
    {
    	int a, b;
    	cin >> a >> b;
    	if(d[a][b] == INF/2) puts("impossible");
    	else cout << d[a][b] << endl;
    }
    return 0;
}