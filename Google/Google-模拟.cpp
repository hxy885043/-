/*
Google Kickstart 2018 Round A Problem A-偶数
*/

#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
typedef long long LL;


int main()
{
	int T;
	cin >> T;
	for(int cases = 1;cases <= T;cases ++)
	{
		LL n;
		cin >> n;
		vector<int> nums;

		LL N = n;
		while(N)
		{
			nums.push_back(N % 10);
			N = N / 10;
		}
		LL add = 0, sub = 0;
		LL res = 0;

		for(int i = nums.size() - 1;i >= 0;i --)
		{
			if(nums[i] % 2 == 0)
			{
				add = add * 10 + nums[i];
				sub = sub * 10 + nums[i];
			}
			else
			{
				// 计算减法
				sub = sub * 10 + nums[i] - 1;
				for(int j = i - 1;j >= 0;j --)
				{
					sub = sub * 10 + 8;
				}
				res = n - sub;

                // 计算加法（去除9的情况）
				if(nums[i] != 9)
				{
					add = add * 10 + nums[i] + 1;
					for(int j = i - 1;j >=0; j --) add = add * 10;
					res = min(res, add - n);
				}
			    break;
			}
		}

		printf("Case #%d: %lld\n",cases,res);
	}
}

