/*
POJ 1274-最佳牛栏
题意：N头牛，M个牛栏，每个牛栏分配头牛，给出每头牛可代的牛栏编号，求最大的可分配的牛栏数目
算法：二分图最大匹配
思路：牛和牛栏分为互不相交两个顶点集，可用二分图求最大匹配
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 210;

vector<int> cows[N];
int match[N];
int visited[N];
int n, m;

bool dfs(int x)
{
	for(int i = 0;i < cows[x].size();i ++)
	{
		int temp = cows[x][i];
		if(!visited[temp])
		{
			visited[temp] = 1;
			if(match[temp] == -1 || dfs(match[temp]))
			{
				match[temp] = x;
				return true;
			}
		}
	}
	return false;
}


int main()
{
	while(scanf("%d%d",&n, &m) != EOF)
	{
		// !!!注意清空vector的内容!!!
	    for(int i = 0;i < n;i ++) cows[i].clear();
	    
	    int k;
    	memset(match, -1, sizeof match);
    	for(int i = 0;i < n;i ++)
    	{
    		cin >> k;
    		for(int j = 0;j < k;j ++)
    		{
    			int a;
    			cin >> a;
    			cows[i].push_back(a);
    		}
    	}
    	int res = 0;
    
    	for(int i = 0;i < n;i ++)
    	{
    		memset(visited, 0, sizeof visited);
    		if(dfs(i)) res ++;
    	}
    	
    	cout << res << endl;
	    
	}
	return 0;

}