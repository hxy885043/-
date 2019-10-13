/*
POJ 3190-建造牛栏
题意：n头奶牛有自己一段连续的产奶时间，求建造最少的牛栏，使得每个奶牛在自己的产奶时间里能单独占用牛栏
算法：区间分组（优先队列+贪心）
思路：将所有奶牛的产奶区间分为互不相交的组别，用区间分组来做。
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 10;

struct node{
    int a, b;
    int id;
    bool operator < (const node &c)const{
        return a < c.a;
    }
}ranges[N];
int stall[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        int a, b;
        cin >> a >> b;
        ranges[i].a = a;
        ranges[i].b = b;
        ranges[i].id = i;
    }
    sort(ranges, ranges + n);
    
    // 小顶堆 pair第一个表示右端点
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    int cnt = 0;
    for(int i = 0;i < n;i ++)
    {
        // 最小的区间右端点与该区间有交集 重新开一个区间
        if(q.empty() || q.top().first >= ranges[i].a) {
            int t = ranges[i].b;
            q.push(make_pair(t, ++cnt));
            stall[ranges[i].id] = cnt ;
        }
        else{
            int count = q.top().second;
            stall[ranges[i].id] = count;
            q.pop();
            q.push(make_pair(ranges[i].b, count));
        }
    }
    
    printf("%d\n",q.size());
    for(int i = 0;i < n;i ++)
    {
        printf("%d\n", stall[i]);
    }
    return 0;
}