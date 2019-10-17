/*
最佳牛围栏
题意：N块地，每块地有在1-2000之间数量的牛，从中选取连续的不小于F块的田地，使得这一段连续块的平均牛的数量最大
     求其最大值
算法：二分+前缀和+双指针
思路：1) 对结果进行二分，其平均值的范围在1-2000之间，选取中点判断该中点和最大平均值的关系，并不断缩小查找范围
     2) 将数组中的所有值减去mid值，并求其前缀和
     3) 用minV标记前i项前缀和的最小值，j标记前j项前缀和，i与j的距离为f
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int cows[N];
double sum[N];
int n, f;

bool check(double x)
{
    sum[0] = 0;
    for(int i = 1;i <= n;i ++) sum[i] = sum[i - 1] + cows[i] - x;
    
    double minV = sum[0];
    for(int i = 0,j = f;j <= n;i ++, j++)
    {
        minV = min(minV, sum[i]);
        if(sum[j] >= minV) return true; 
    }
    return false;
}

int main()
{
    cin >> n >> f;
    for(int i = 1;i <= n;i ++) cin >> cows[i];
    
    double left = 1, right = 2000;
    while(right - left > 1e-5)
    {
        double mid = (left + right) / 2;
        if(check(mid)) left = mid;
        else right = mid;
    }
    printf("%d\n",(int)(right * 1000));
    return 0;
}