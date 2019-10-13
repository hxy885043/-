/*
POJ 2010-Moo大学经济资助
题意：从C个申请者里录取规定的n个人，要求他们的需要经济救助的资金不超过预算，且是的录取分数的中位数最大
算法：优先队列
思路：将所有申请者的成绩按从小到大排序，并枚举每个申请者为中位数时，其左右n/2个数的最小资金和，找到不超过预算的
      最大中位数
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;

struct node
{
	int score;
	LL fina;
	bool operator < (const node &c)const{
		return score < c.score;
	}
}cows[N];

priority_queue<int> p;

LL lower[N], upper[N];

int main()
{

	int n, c;
	LL f;
	cin >> n >> c >> f;
	for(int i = 0;i < c;i ++)
	{
		int a, b;
		cin >> a >> b;
		cows[i].score = a;
		cows[i].fina = b;
	}

	sort(cows, cows + c);

	int odd = n / 2;
    LL sum = 0;
	for(int i = 0;i < c;i ++)
	{
		if(i < odd){
			p.push(cows[i].fina);
			sum += cows[i].fina;
			continue;
		}
		lower[i] = sum;
		if(cows[i].fina >= p.top()) continue;
		sum -= p.top();
		p.pop();
		sum += cows[i].fina;
		p.push(cows[i].fina);

	}

	while(p.size()) p.pop();
	sum = 0;


	for(int i = c - 1;i >= 0;i --)
	{
		if(i >= c - odd){
			p.push(cows[i].fina);
			sum += cows[i].fina;
			continue;
		}
		upper[i] = sum;
		if(cows[i].fina >= p.top()) continue;
		sum -= p.top();
		p.pop();
		sum += cows[i].fina;
		p.push(cows[i].fina);

	}


	for(int i = c - 1 - odd;i >= odd;i --)
	{
		if(lower[i] + upper[i] + cows[i].fina <= f)
		{
			printf("%d\n", cows[i].score );
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}