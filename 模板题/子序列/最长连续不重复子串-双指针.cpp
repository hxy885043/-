/*
最长连续不重复子序列：找出最长的不包含重复数字的连续区间，输出长度
思路：双指针，定义一个指针为区间开头，一个指针为区间结尾，尾指针不断向后移动，直到碰到重复数字，
      然后开始移动头指针，直到碰到重复数字的位置，将该数字后一位定位头指针，之后再移动尾指针，
      不断循环，并进行比较长度。重复数字的记录另开一个数组记录。
时间复杂度：O(n^2)
*/
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;
int nums[N];
int s[N];

int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n;i ++) cin >> nums[i];
    int res = 0;

    // i为终点，j为终点
	for(int i = 0, j = 0;i < n;i ++)
	{
		s[nums[i]] ++;
		// 出现重复数字，将前面记录清空，重新定义起点
		while(j < i && s[nums[i]] > 1)
		{
			s[nums[j]] --;
			j ++;
		}
		res = max(res, i - j + 1);
	}
	cout << res << endl;
	return 0;
}