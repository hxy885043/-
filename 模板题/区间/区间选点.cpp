/*
区间选点：
题意：给定N个闭区间，请你在数轴上选择尽量少的点，使得每个区间内至少包含一个选出的点。输出选择的点的最小数量。
      位于区间端点上的点也算作区间内。
思路：选取区间的右端点可以包括可能多的区间，因此对区间的右端点进行排序，并遍历每一个区间，若下一个区间的左端点大于当前区间的右端点，则需要加点。
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

struct node
{
    int a, b;
    bool operator < (const node &c) const{
        return b < c.b;
    }
}nodes[N];

int main()
{
	int n;
	cin >> n;
	for(int i = 1;i <= n;i ++)
	{
	   int s1, t1;
	   cin >> s1 >> t1;
	   nodes[i].a = s1;
	   nodes[i].b = t1;
 	}
 	
 	sort(nodes + 1, nodes + 1 + n);
 	
 	int temp = nodes[1].b;
 	int res = 1;
 	for(int i = 2;i <= n;i ++)
 	{
 	    if(nodes[i].a > temp){
 	        temp = nodes[i].b;
 	        res ++;
 	    }
 	}
 	
 	printf("%d\n", res);
 	return 0;

}