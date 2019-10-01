/*
最小生成树-Kruskal:
适用范围：用于寻找图中权值和最小的树
思路：1）把图中所有的权值从小到大排序；2）n个顶点视为独立的子树；3）按权值从小到大枚举边，所选的边连接的两个顶点ui,vi如果不连通，
则将它们成为最小生成树集合的一条边（并查集的思想），并将这两颗树合并作为一颗树；4）重复(3),直到所有顶点都在一颗树内或者有n-1条边为止。
*/
#include <iostream>
#include <algorithm>

using namespace std;

// N为最大顶点数 M为最大边数
// const表示对该值进行保护，不允许通过复制来改变它的值
// INF = 0x3f3f3f3f表示无穷大，10^9量级 原因：1）INF + 有穷数 = INF，不会超过int范围；2）可以使用memeset(a,0x3f,sizeof(a))，不需要循环遍历赋值
const int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;

int n, m;
// p数组存储父节点
int p[N];

struct Edge
{
	int u, v; // u.v表示边的两个节点
	int w; // w表示边上的权重

	// 结构体内的嵌套比较函数，当对结构体进行排序时，按照权值的大小从大到小排
	bool operator < (const Edge &T)const{
		return w < T.w;
	}
}edges[M];


// 并查集寻找父节点
int find(int x)
{
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int kruskal()
{
	sort(edges, edges + m);
	// 初始化并查集的父节点，每个节点的父节点都是它本身
	for(int i = 1;i <= n;i ++) p[i] = i;
    
    // res表示权重之和，cnt表示边数
	int res = 0, cnt = 0;
    for(int i = 0;i < m;i ++)
    {
    	Edge t = edges[i];
    	// 找到这条边两个顶点所在的父节点，若都是同一个父节点，说明已在同一个子集中，无需添加，若不相等，说明处在不同的子集中，将边加入
    	t.u = find(edges[i].u);
    	t.v = find(edges[i].v);
    	if(t.u != t.v)
    	{
    		p[t.u] = t.v;
    		res += t.w;
    		cnt ++;
    	}
    }

    if(cnt < n - 1) return INF;
    return res;
}

int main()
{
	cin >> n >> m;

	int u, v, w;
	for(int i = 0;i < m;i ++)
	{
		cin >> u >> v >> w;
		edges[i].u = u;
		edges[i].v = v;
		edges[i].w = w;
	}

	int x = kruskal();
	if(x > INF / 2) puts("impossible");
	else cout << x << endl;
}