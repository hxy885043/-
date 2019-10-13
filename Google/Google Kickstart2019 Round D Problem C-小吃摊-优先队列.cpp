/*
Google Kickstart2019 Round D Problem C：小吃摊
题意：在一条街上建立k个小吃摊和一个仓库，给出N个点，每个点有到第一个点的距离和建造费用，建造费用还需加上
     仓库到每个小吃摊的距离，求选择K个小吃摊和一个仓库的最小费用
算法：优先队列
思路：假设选好了k个点，则仓库建在这k个点的中间会使得费用最小。于是我们可以遍历每个点当作仓库，计算仓库左边
      及右边k/2的最小费用，用大顶堆来维护。
*/

/*
方法一：进行两次遍历，第一次遍历计算前i个点选择k/2个小吃摊的最小费用，并保存到lower数组中，第二次遍历计算
后k/2个点的最小费用，并保存到upper数组中去。同时遍历lower和upper数组，计算两数之和的最小值
*/
#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
typedef long long LL;


struct node 
{
    LL x, c;
    bool operator < (const node &c)const{
    	return x < c.x;
    }
}pos[N];

priority_queue<LL> q;
LL lower[N], upper[N];

int main()
{
	int T;
	cin >> T;
	for(int cases = 1;cases <= T;cases ++)
	{
		int k, n;
        cin >> k >> n;
        int dis, cost;
        for(int i = 1;i <= n;i ++){
            cin >> dis;
            pos[i].x = dis;
        }
        for(int i = 1;i <= n;i ++){
            cin >> cost;
            pos[i].c = cost;
        }
        // 按距离从小到大排序
        sort(pos + 1, pos + 1 + n);
        
        
        while(q.size()) q.pop();
        LL sum = 0;
        int k1 = k / 2, k2 = k - k1;
        
        
        if(k1)
        {
            for(int i = 1;i <= n;i ++)
            {
            	if(i <= k1){
            		q.push(pos[i].c - pos[i].x);
            		sum += pos[i].c - pos[i].x;
            		continue;
            	}
            	lower[i] = sum;
            	if(pos[i].c - pos[i].x >= q.top()) continue;
            	sum -= q.top();
            	q.pop();
            	sum += pos[i].c - pos[i].x;
            	q.push(pos[i].c - pos[i].x);
            }
            
        }

        while(q.size()) q.pop();
        sum = 0;

    	for(int i = n;i >= 1;i --)
        {
        	if(i >= n + 1 - k2){
        		q.push(pos[i].c + pos[i].x);
        		sum += pos[i].c + pos[i].x;
        		continue;
        	}
        	upper[i] = sum;
        	if(pos[i].c + pos[i].x >= q.top()) continue;
        	sum -= q.top();
        	q.pop();
        	sum += pos[i].c + pos[i].x;
        	q.push(pos[i].c + pos[i].x);
        }

        LL res = LONG_MAX;
        
        if(k1)
        {
            for(int i = k1 + 1;i <= n - k2;i ++)
            {

    		    res = min(res, lower[i] + upper[i] + pos[i].c + (k1 - k2) * pos[i].x);
            }
            printf("Case #%d: %lld\n", cases, res);            
        }
        else
        {
            for(int i = 1;i <= n - 1;i ++)
            {
                res = min(res, upper[i] + pos[i].c + (k1 - k2) * pos[i].x);
            }
            printf("Case #%d: %lld\n", cases, res); 
        }

	}
}

/*
方法二：将前k1个放入大顶堆中去，其余加入小顶堆去，set维护右边k2个数，并不断遍历所有可能的中点，并判断放入左边的堆
从小顶堆中取数。
*/

#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
typedef long long LL;
// 第一个表示权值大小，第二个表示位置
typedef pair<int,int> PII;

LL res = INF;

struct node 
{
    int x, c;
}pos[N];

// 记录右边k2个最小的值
set<int> s;
// 大顶堆
priority_queue<int> q1;
// 小顶堆
priority_queue<PII, vector<PII>, greater<PII> > q2;
bool cmp(const node &a, const node &b)
{
    return a.x < b.x;
}

int main()
{
    int T;
    cin >> T;
    for(int cases = 1;cases <= T;cases ++)
    {
        int k, n;
        cin >> k >> n;
        int dis, cost;
        for(int i = 1;i <= n;i ++){
            cin >> dis;
            pos[i].x = dis;
        }
        for(int i = 1;i <= n;i ++){
            cin >> cost;
            pos[i].c = cost;
        }
        // 按距离从到大排序
        sort(pos + 1, pos + 1 + n, cmp);
        
        // 清空队列
        while(q1.size()) q1.pop();
        while(q2.size()) q2.pop();
        s.clear();
        
        // 仓库在中间时会使得到两边距离最短
        int k1 = k / 2, k2 = k - k1;
        // 设初始仓库地址为k1 + 1
        LL temp = pos[k1 + 1].c;
        // 将前k1个入队 形成包含k1个数的最大堆
        for(int i = 1;i <= k1;i ++) {
            q1.push(pos[i].c - pos[i].x);
            temp += pos[i].c - pos[i].x;
        }
        for(int i = k1 + 2;i <= n;i ++)
        {
            q2.push(make_pair(pos[i].c + pos[i].x, i));
        }
        for(int i = 1;i <= k2;i ++)
        {
            PII p = q2.top();
            q2.pop();
            temp += p.first;
            s.insert(p.second);
        }

        temp = temp + k1 * pos[k1 + 1].x - k2 * pos[k1 + 1].x;
        res  = temp;
        // 遍历每一个可能的仓库点
        for(int i = k1 + 2;i <= n - k2;i ++)
        {
            temp += k1 * (pos[i].x - pos[i - 1].x) + k2 * (pos[i - 1].x - pos[i].x);
            temp += pos[i].c - pos[i - 1].c;
            
            //printf("%lld\n", temp);

            int t = pos[i - 1].c - pos[i - 1].x;
            if(!q1.empty() && t < q1.top()){
                temp += t - q1.top();
                q1.pop();
                q1.push(t);
            }

            if(s.begin() != s.end()){
                if((*s.begin()) == i){
                    s.erase(s.begin());
                    temp -= pos[i].c + pos[i].x;
                    PII p;
                    do{
                        p = q2.top();
                        q2.pop();
                    }while(p.second <= i);
                    temp += p.first;
                    s.insert(p.second);
                }
            }
            res = min(res, temp);

        }

        printf("Case #%d: %lld\n", cases, res);
        
    }
}