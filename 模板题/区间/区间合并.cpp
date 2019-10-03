/*
区间合并；给定n个区间，要求合并所有有交集的区间
思路：将所有区间按起点进行排序，并动态维护一个可合并的区间，将下一个区间的起点和动态区间的终点进行比较
      若小于等于终点，说明可以进行合并，更新动态区间终点的最大值，若大于，说明两个区间不可合并。
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

typedef pair<int, int> PII;
vector<PII> alls;

int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n;i ++)
	{
		int left, right;
		cin >> left >> right;
		alls.push_back({left, right});
	}
	sort(alls.begin(), alls.end());

	int first = alls[0].first, last = alls[0].second;
	int cnt = 1;

	for(int i = 1;i < alls.size();i ++)
	{
		if(alls[i].first <= last) last = max(last,alls[i].second);
		else {
		    cnt ++;
		    first = alls[i].first; 
		    last = alls[i].second;
		}
	}
	printf("%d\n", cnt);
}