/*
STL:unique(begin, end)-前开后闭，指向去重后容器中不重复序列的最后一个数的下一个元素
    erase(begin, end)-删除[begin, end)中的所有字符，并返回一个指向被删除的最后一个元素的下一个元素的迭代器
*/
/*
区间和:假定有一个无限长的数轴，数轴上每个坐标上的数都是0;现在，我们首先进行 n 次操作，每次操作将某一位置x上的数加c。
       接下来，进行 m 次询问，每个询问包含两个整数l和r，你需要求出在区间[l, r]之间的所有数的和。
思路:由于坐标轴范围太大，开如此大的数组范围不现实，由于不是所有坐标点上都有数字，可采用将坐标离散化的方法，用一个数组
     存储有记录的下标，进行排序，然后再用一个数组记录对应的值，计算前缀和，可求得区间和。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 3e5 + 10;

typedef pair<int, int> PII;
// a数组存储每个对应每个离散化下标点的值
// s数组存储前缀和
int a[N], s[N];
int n, m;

// 存储所有的下标
vector<int> alls;
vector<PII> add, query;


// 寻找下标离散化的点坐标,即第一个大于等于x的坐标
int find(int x)
{
	int left = 0, right = alls.size() - 1;
	while(left < right)
	{
		int mid = (left + right) / 2;
		if(alls[mid] >= x) right = mid;
		else left = mid + 1;
	}
	// 为了后续前缀和的处理，返回下标加1
	return left + 1;
}

int main()
{
	cin >> n >> m;
	for(int i = 0;i < n;i ++)
	{
		int x, c;
		cin >> x >> c;
		add.push_back({x, c});
		alls.push_back(x);
	}

	for(int i = 0;i < m;i ++)
	{
		int left, right;
		cin >> left >> right;
		query.push_back({left, right});
		alls.push_back(left);
		alls.push_back(right);
	}

    // 将所有下标点从大到小排序并去重，以遍后续进行二分查找
	sort(alls.begin(), alls.end());
	vector<int>::iterator it = unique(alls.begin(), alls.end());
	alls.erase(it,alls.end());

    // 将下标点对应的数存入a数组
	for(int i = 0;i < add.size();i++)
	{
		PII p = add[i];
		int x = find(p.first);
		a[x] += p.second;
	}
	for(int i = 1; i <= alls.size(); i ++ ) s[i] = s[i - 1] + a[i];

	for(int i = 0;i < query.size();i ++)
	{
		PII p = query[i];
		int left = find(p.first), right = find(p.second);
		cout << s[right] - s[left - 1] << endl;
	}
	return 0;
}