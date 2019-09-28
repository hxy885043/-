/*
Google Kick Start 2019 Round B:palindromes(回文)
题意：回文是指从前读和从后读都是一样的字符串，比如ANNA，AAA，X。
思路：回文字符串的特征是每个数字的次数均为偶数个或者只有一个字母为奇数个其余都是偶数个
*/


#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, q;
char str[N];
// 前26个字母的在数组的前缀和 s[0][i]表示前i个元素中A的个数
int s[26][N];

int main()
{
	int T;
	cin >> T;
	for(int C = 1;C <= T;C++)
	{
		cin >> n >> q;
		//将数据存在Str[1]开始的地方
		scanf("%s", str + 1);
		for(int i = 1; i <= n; i++)
			for(int j = 0; j < 26; j++)
				if(str[i] == 'A' + j)
					s[j][i] = s[j][i-1] + 1;
				else
					s[j][i] = s[j][i-1];
		int res = 0;
		for(int i = 1;i <= q;i++)
		{
			int left, right;
			cin >> left >> right;
            //统计奇数的个数
			int cnt = 0;
			for(int j = 0; j < 26; j++)
			{
				int sum = s[j][right] - s[j][left - 1];
				if(sum%2 != 0) cnt ++;

			}
			if(cnt <= 1) res ++;
		}

		printf("Case #%d: %d\n",C, res );

	}
	return 0;
}