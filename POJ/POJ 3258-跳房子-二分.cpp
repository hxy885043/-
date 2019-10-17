/*
POJ 3258-跳房子
题意：一段长l的河，其中有若干个石头及他们到起点的距离，移除任意m个石头，在所有的移除可能中，求相邻石头间最短
     距离的最大值
算法：二分
思路：对距离进行二分，判断是否能在移除石头个数小于m的情况下能保持相邻石头间的距离小于mid
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 5e4 + 10;
int arr[N];
int l, n, m;

bool check(int x)
{
	int start = 0, jump = 0;
	for(int i = 0;i < n;i ++)
	{
		if(arr[i] - start < x) jump ++;
		else start = arr[i];
	}

	if(l - start < x) return false;
	if(jump > m) return false;
	return true;
}

int main()
{
	cin >> l >> n >> m;
	for(int i = 0;i < n;i ++) cin >> arr[i];
	sort(arr, arr + n);
    
    int left = 1, right = l;
    while(left < right)
    {
    	int mid = (left + right + 1) / 2;
    	if(check(mid)) left = mid;
    	else right = mid - 1;
    }

    cout << left << endl;
    return 0;
}