/*
NOIP2003普及组-乒乓球
题意：乒乓球分制由11分改为21分，给定一串字符串，分别统计11分制和21分制下的比分
算法：字符串处理，模拟
思路：注意结束条件的设置，某一方达到指定分，且分差到达2
时间复杂度：O(n)
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void solve(string str, int score)
{
	int a = 0, b = 0;
	for(int i = 0;i < str.size() && str[i] != 'E';i ++)
	{
		if(str[i] == 'W') a ++;
		else b ++;

		if(max(a, b) >= score && abs(a - b) >= 2){
			printf("%d:%d\n",a, b);
			a = b = 0;
		}
	}
	printf("%d:%d\n",a, b);
}

int main()
{
	string s, str;
	while(cin >> s) str += s;

	solve(str, 11);
	puts(""); 
	solve(str, 21);

	return 0;
}