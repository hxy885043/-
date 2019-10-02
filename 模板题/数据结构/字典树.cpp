/*
字典树:实现插入词和查询词的操作

ASCII码：'0'- 48, 'A'- 65, 'a' - 97
*/

#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int son[N][26]; // N表示每个节点，26表示与它相连接的所有子节点，字符范围在0-25，也就是说son数组存的是每个子节点的编号
int cnt[N]; // 最终词的插入个数
int idx = 0; // 节点编号
char str[N];

void insert(char s[])
{
	// 从父节点开始插入
	int p = 0;
	for(int i = 0;s[i];i ++)
	{
		int u = s[i] - 'a';
		if(!son[p][u]) son[p][u] = ++idx;
		p = son[p][u];
	}
	cnt[p]++;
}

int query(char s[])
{
	int p = 0;
	for(int i = 0;s[i];i ++)
	{
		int u = s[i] - 'a';
		if(!son[p][u]) return 0;
		p = son[p][u];
	}
	return cnt[p];
}

int main()
{
	int n;
	cin >> n;
	char op[2];
	while(n --)
	{
		scanf("%s%s", op, str);
		if(op[0] == 'I') insert(str);
		else printf("%d\n", query(str));
	}
	return 0;
}