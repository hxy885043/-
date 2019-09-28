/*
Google Kick Start 2019-Round A :training
题意：给定一个长为N的数组，从中选取P个元素，使得这P个数中最大的那个数与剩余P-1个数的差值之和最小
思路：贪心思想：1）对数组进行排序 2）求数组前缀和 3）遍历每一个长度为P的序列，不断更新最小值
      假定给定一个数字是最大的，从中选取小于该数字的剩余P-1个值，根据贪心思想，则选择与它最相近
      的P-1个数，这样会使得其差值最小
*/

#include <iostream>
#include <algorithm>
// limits.h头文件定义了各个类型的取值范围
// 例如：INT_MAX = 2147483647
#include <limits.h>

using namespace std;

const int N = 100010;

int n, p;
int skill[N],sum[N];

int main()
{
		int T;
	cin >> T;
	for(int C = 1; C <= T; C++)
	{
		cin >> n >> p;
		for(int i = 1; i <= n; i++) cin >> skill[i];
		sort(skill + 1,skill + 1 + n);
	    for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + skill[i];

	    int res = INT_MAX;
	    for(int i = p; i <= n; i++)
	    {
	    	res = min(res, p * skill[i] - (sum[i] - sum[i-p]));
	    }
	    printf("Case #%d: %d\n", C , res);
	}
	return 0;
}


	
