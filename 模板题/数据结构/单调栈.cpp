/*
单调栈：给定一个长度为N的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出-1。
思路：从栈顶开始寻找比nums[i]小的数，直至找到输出或者栈为空，把nums[i]加入栈中，该栈永远是单调递增的
*/
#include <iostream>
#include <stack>
using namespace std;

const int N = 100010;

int nums[N];
stack<int> stk;

int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n;i ++) cin >> nums[i];

	for(int i = 0;i < n;i ++)
	{
		while(!stk.empty() && stk.top() >= nums[i]) stk.pop();
		if(stk.empty()) printf("-1 ");
		else printf("%d ",stk.top());
		stk.push(nums[i]);
	}
	return 0;
}
