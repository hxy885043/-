/*
最长异或值路径：
题意：给定一个树，树上的边都具有权值。树中一条路径的异或长度被定义为路径上所有边的权值的异或和，给定n个节点的树，找到最长的异或值路径。
范围：1≤N≤1e5, 0≤u,v＜n,0 ≤ w ＜2^31
算法：DFS + 字典树 + 贪心
-------------------------------------------------------------------------------------------------------------------------
输入：
4        （n）
0 1 3     (u, v, w)
1 2 4
1 3 6
输出：
7
--------------------------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5 + 10, M = 3e6 + 10;

vector<pair<int, int>> adj[N];
int a[N];
int son[M][2];
int idx = 0;
// 求根节点到所有其他节点的路径异或和
void dfs(int u, int father, int sum){
    a[u] = sum;
    for(int i = 0;i < adj[u].size();i ++){
        if(adj[u][i].first != father){  // 无向图要注意防止往回走
            dfs(adj[u][i].first, u, sum ^ adj[u][i].second);
        }
    }
}

void insert(int x){
    int p = 0;
    for(int i = 30;i >= 0;i --){
        int t = (x >> i) & 1;
        if(!son[p][t]) son[p][t] = ++idx;
        p = son[p][t];
    }
}


int query(int x){
    int p = 0;
    int res = 0;
    for(int i = 30;i >= 0;i --){
        int t = (x >> i) & 1;
        if(son[p][!t]){
            res += 1 << i;
            p = son[p][!t];
        }else p = son[p][t];
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    dfs(0, -1, 0);
    for(int i = 0;i < n;i ++) insert(a[i]);
    
    int res = 0;
    for(int i = 0;i < n;i ++){
        res = max(res, query(a[i]));
    }
    cout << res << endl;
    return 0;
}