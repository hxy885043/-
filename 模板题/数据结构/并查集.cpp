/*
并查集：判断两个点是否在一个子集中
*/
#include <iostream>

using namespace std;

const int N = 1e5 +10;
int father[N];
int n, m;

int find(int x)
{
	if(father[x] != x) father[x] =find(father[x]);
	return father[x];
}

int main()
{
	cin >> n >> m;
	for(int i = 0;i <= n;i ++) father[i] = i;
	for(int i = 0;i < m;i ++)
	{
		char ch;
		int a, b;
		cin >> ch >> a >> b;
		if(ch == 'M')
		{
			father[find(a)] = find(b);
		}
		else
		{
			int p = find(a);
			int q = find(b);
			if(p == q) printf("Yes\n");
			else printf("No\n");
		}
	}

}