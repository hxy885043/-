/*
区间分组：
题意：给定N个闭区间，将其分为互不相交的组别
算法：优先队列+贪心
思路：将所有区间按左端点排序，用最小堆维护区间的右端点，在遍历区间时，若该区间的左端点比堆顶的值小，说明
      该区间与堆顶区间有重合，需要将其放入新的区间中去，相反，将堆顶弹出，并将该区间的右端点压入堆。
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 10;

struct node{
    int a, b;
    bool operator < (const node &c)const{
        return a < c.a;
    }
}range[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        int a, b;
        cin >> a >> b;
        range[i]={a, b};
    }
    sort(range, range + n);
    
    // 小顶堆
    priority_queue<int, vector<int>, greater<int> > q;
    
    for(int i = 0;i < n;i ++)
    {
        // 最小的区间右端点与该区间有交集 重新开一个区间
        if(q.empty() || q.top() >= range[i].a) q.push(range[i].b);
        else{
            q.pop();
            q.push(range[i].b);
        }
    }
    
    printf("%d\n",q.size());
    return 0;
}