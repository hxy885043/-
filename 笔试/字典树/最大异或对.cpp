/*
最大异或对
题意：在 N 个整数 A1, A2, ...，An任意选取两个进行异或运算，求其最大值。 
范围：1≤ N ≤ 10^5, 0 ≤ Ai＜2^31
算法：字典树+贪心
-----------------------------------------------------------------
输入：
3        （N）
1  2  3   (A1, ..., An)
输出：
3
-----------------------------------------------------------------
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10, M = 3e6 + 10;
// 每个节点0,1表示
int son[M][2];
int idx = 0;
int a[N];
// 将一个数看做01二进制序列插入
void insert(int x){
    int p = 0;
    for(int i = 30;i >= 0;i --){
        int t = (x >> i) & 1;
        if(!son[p][t]) son[p][t] = ++idx;
        p = son[p][t];
    }
}

// 边查询边记录最大结果
int query(int x){
    int res = 0;
    int p = 0;
    for(int i = 30;i >= 0;i --){
        int t = (x >> i) & 1;
        if(son[p][!t]){         // 判断当前位置是否存在与其相反节点
          p = son[p][!t];
          res += 1 << i;
        }
        else p = son[p][t];
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++){
        cin >> a[i];
        insert(a[i]);
    }
    
    int res = 0;
    for(int i = 0;i < n;i ++){
        res = max(res, query(a[i]));
    }
    cout << res << endl;
    
    return 0;
}