/*
糖果(Google Kickstart2018 Round D Problem A/ Acwing 546):
题目描述：给定一个长度为N的数组S，求满足和小于等于D，奇数的个数小于O的连续子序列中其序列和最大的值
算法：双指针+动态数组（set）
分析：1）先求出所有满足奇数个数小于O的连续子序列（通过动态集合set添加和删除元素，以i为终点，奇数个数小于等于O的最大长度连续子序列）
     2）对于每个以i为终点的子序列，找出和小于等于D，且最大的那个序列
     3）s[i]表示前i个数的前缀和，s[i]-s[j]<=D且s[i]-s[j]需最大，s[i]与D都是已知数，问题转化过来就是s[j]>=s[i]-D的条件下s[j]的min值
 */

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

typedef long long LL;
const int N = 500010;
//全局变量默认初始化为0 即s[0]=0
LL x[N], s[N];

int main()
{
	int T;
	cin >> T;

	for(int cases = 1; cases <= T; cases++)
	{
		int n, o;
		LL d;
		int A, B, C, M, L;
		cin >> n >> o >> d;
		cin >> x[1] >> x[2] >> A >> B >> C >> M >> L;
		for(int i = 3; i <= n; i++) x[i] = (A * x[i-1] + B * x[i-2] + C) % M;
        for(int i = 1; i <= n; i++) s[i] = x[i] + L;
        //S[i]存储前缀序列和
        for(int i = 1; i <= n; i++) s[i] += s[i-1];

        multiset<LL> S;
        LL res = -1e18;
        S.insert(0);

        //i表示连续序列的终点，j表示起点的前一个位置
        for(int i = 1, j = 0, odds = 0; i <= n; i ++)
        {
        	//&1可以提取前一个数二进制的最后一位，判断奇偶性
        	if((s[i] - s[i-1]) & 1) odds ++;
        	while(odds > o)
        	{
        		S.erase(S.find(s[j]));
        		if((s[j+1] - s[j]) & 1) odds--;
        		j++;
        	}

        	auto it = S.lower_bound(s[i] - d);
        	if(it != S.end()) res = max(res, s[i] - *it);

        	S.insert(s[i]); 
        }

        if(res == -1e18) printf("Case #%d: IMPOSSIBLE\n", cases);
        else printf("Case #%d: %lld\n",cases, res);
	}
}



/*
算法二：暴力法
分析：枚举所有的连续序列，对每个枚举的序列进行判断O与D是否符合条件
     i代表序列起始位置，j代表重点位子，若奇数个数大于O，则提前退出以i为起点的循环，进入i+1为起点的循环，
     否则进行判断d之和是否大于D，是否需要更新最大值
 */
//以下为伪代码
for(int i=1;i<=n;++i)
	for(int j=i;j<=n;++j){
		if(sum(odds)>O) break;
		if(sum(d)<D) res=max(res,sum(d))
	}



/*
知识扩充——set/multiset:
1）set是一种关联式容器，底层通过平衡搜索树实现，插入删除操作时只涉及到节点的操作，不涉及内存移动和拷贝，因此效率较高；
2）lower_bound（x）:二分查找大于等于x的第一个值（最小值），upper_bound(x):二分查找大于x的最小值
3）set值去重，且有序；multiset值不去重，且有序
 