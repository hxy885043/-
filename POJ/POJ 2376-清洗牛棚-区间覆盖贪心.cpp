/*
POJ 2376-清洗牛棚
题意：有N头奶牛，每个奶牛可以清洗一段连续的牛棚区间，问最少用几头奶牛可以清洗完成所有的牛棚
算法：区间覆盖-贪心
思路：将N个区间按起始点排序，从前向后依次枚举每个区间，若1-p已覆盖，从剩余区间中中选取起点不大于p，且终点最大
      的区间，并将起点更新为p + 1，重复上述操作。
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 25010, INF = 0x3f3f3f3f;

struct  node
{
	int a, b;
	bool operator < (const node &c) const{
		return a < c.a;
	}
}cows[N];

int main()
{
	int n, t;
	scanf("%d%d", &n, &t);
	for(int i = 0;i < n;i ++){
		int s1, t1;
		scanf("%d%d",&s1, &t1);
		cows[i].a = s1;
		cows[i].b = t1;
	}

	sort(cows, cows + n);
	int res = 0;
	int first = 1;
	for(int i = 0;i < n;i ++)
	{
		int j = i, last = -INF;
		while(j < n && cows[j].a <= first){
			last = max(last, cows[j].b);
			j ++;
		}

		if(last < first) 
		{
			printf("-1\n");
			return 0;
		}

		res ++;
		if(last >= t)
		{
			printf("%d\n", res);
			return 0;
		}
		first = last + 1;
		i = j - 1;
	}
	// 当最大的last不能大于t时返回-1
	printf("-1\n");
	return 0;
}