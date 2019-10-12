/*
POJ 1328-雷达安装
题意：给出n个岛的坐标，在x轴上放置半径为d的雷达，求使得所有岛被覆盖的最少的雷达数量
算法：区间选点
思路：可以求出每个海岛被雷达覆盖的边界值，因为雷达只在x轴上移动，因此可求出每个海岛被覆盖的雷达最左边的坐标
      和最右边的坐标，问题可转化为在n个区间中选取尽可能少的点，使得每个区间至少包含一个选出的点
*/
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1010, INF = 0x3f3f3f3f;

struct  node
{
	int a, b;
	double x1, x2;
	bool operator < (const node &c) const{
		return x2 < c.x2;
	}
}island[N];

int main()
{
	int n, d;
	int cases = 0;
	while(scanf("%d%d", &n, &d) != EOF && n && d)
	{
		bool flag = true;
		for(int i = 0;i < n;i ++){
			int s1, t1;
			scanf("%d%d",&s1, &t1);
			if(t1 > d){
				flag = false;
				continue;
			}
			island[i].a = s1;
			island[i].b = t1;
			island[i].x1 = s1 - (double)sqrt((double)d * d - (double)t1 * t1);
			island[i].x2 = s1 + (double)sqrt((double)d * d - (double)t1 * t1);
		}
		if(!flag) {
			printf("Case %d: -1\n", ++cases);
			continue;
		}


		sort(island, island + n);
		int res = 1;
		double temp = island[0].x2;

		for(int i = 1;i < n;i ++)
		{
			if(island[i].x1 > temp){
				temp = island[i].x2;
				res ++;
			}
		}
		printf("Case %d: %d\n", ++cases, res);
	}

	return 0;
}