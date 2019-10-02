/*
模拟栈：push, top, empty, pop
*/
#include <iostream>

using namespace std;

const int M = 100010;
int stk[M];
int cnt = 0;

void push(int x)
{
	stk[++ cnt] = x;
}

int query()
{
	return stk[cnt];
}

void pop()
{
	cnt --;
}

int empty()
{
	if(cnt == 0) return 1;
	else return 0;
}

int main()
{
	int m;
	cin >> m;
	string s;

	for(int i = 0;i < m;i ++)
	{
		cin >> s;
		int k;
		if(s == "push")
		{	
			cin >> k;
			push(k);
		}
		else if (s == "query")
		{
			printf("%d\n", query());
		}
		else if (s == "pop")
		{
			pop();
		}
		else if (s == "empty")
		{
			if(empty() == 1) printf("YES\n");
			else printf("NO\n"); 
		}
	}
	return 0;
}