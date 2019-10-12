/*
区间覆盖：
题意：给定N个闭区间以及一个线段区间，请你选择尽量少的区间，将指定线段区间完全覆盖
思路：1）将所有区间按左端点从小到大排序
     2）对于所有能覆盖start的区间中，选择右端点最大的区间，然后更新start为右端点最大值
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

struct  node
{
	int a, b;
	// 按从小到大排序，若在优先队列中是从大到小排
	bool operator < (const node &c) const{
		return a < c.a;
	}
}ranges[N];

int main()
{
	int s, t;
	cin >> s >> t;
	int n;
	cin >> n;
	for(int i = 0;i < n;i ++)
	{
		int s1, t1;
		cin >> s1 >> t1;
		ranges[i].a = s1;
		ranges[i].b = t1;
	}

	sort(ranges, ranges + n);

	int res = 0;
    int first = s;
	for(int i = 0;i < n;i ++)
	{
		int j = i, last = -INF;
		while(j < n && ranges[j].a <= first){
			last = max(last, ranges[j].b);
			j ++;
		}

		if(last < first) 
		{
			printf("-1\n");
			return 0;
		}

		res ++;

		if(last >= t){
			printf("%d\n", res);
			return 0;

		}
		first = last;
		i = j - 1;
	}
	return 0;
}

