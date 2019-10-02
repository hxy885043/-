/*
模拟队列：push, top, empty, pop
*/
#include <iostream>

using namespace std;

const int M = 100010;
int queue[M];
// 队首队尾
int last = -1;
int first = 0;

void push(int x)
{
	queue[++ last] = x;
}

int query()
{
	return queue[first];
}

void pop()
{
	first ++;
}

int empty()
{
	if(last < first) return 1;
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