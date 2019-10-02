/*
KMP：字符串匹配
思路：1）获取模板串的Next数组，Next[i]表示下标为0~i-1的数组前缀和后缀相同的最大长度
     2) 同时遍历模式串和模板串，若相同，同时后移，若不相同，则从next[i]处开始比较
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 10010, M = 100010;

int n, m;
char a[N];
char b[M];
int Next[N];

void GetNext(char s[], int n)
{
	int i = 0, j = -1;
	Next[0] = -1;

	while(i <= n - 1)
	{
		if(j == -1 || s[i] == s[j])
		{
			i ++;j ++;
			Next[i] = j;
		}
		else j = Next[j];
	}

}
// 模式串s, 模板串p
void Kmp(char p[], char s[], int n, int m)
{
	GetNext(p, n);
	int i = 0;
	int j = 0;

	while(j < m)
	{
		while(i < n && j < m)
		{ 
			if(i == -1 || p[i] == s[j])
			{
				i ++;j ++;
			}
			// 字符串匹配失败，跳转到next进行匹配
			else i = Next[i];
		}
		if(i == n) {printf("%d ",j - n); i = Next[i];}
	}

}


int main()
{
	cin >> n;
	scanf("%s", a);
	cin >> m;
	scanf("%s", b);
	Kmp(a, b, n, m);
	return 0;
}