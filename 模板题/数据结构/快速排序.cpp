/*
快速排序：
思路：1）从数列中取出一个数作为基准
     2）将数组进行划分，把比基准大的划分到基准右边，小的划分到左边
     3）再对左右区间重复进行一二步操作，直至每个区间只有一个数
时间复杂度：O(nlogn) 最坏情况：O(n^2)
空间复杂度：O(logn)
稳定性：不稳定
*/

#include <iostream>

using namespace std;

const int N = 100010;

int nums[N];

int partition(int nums[], int left, int right)
{
    int i = left, j = right;
    int x = nums[left];
    while(i < j)
    {
        while(i < j && nums[j] >= x) j --;
        if(i < j) nums[i ++] = nums[j];
        while(i < j && nums[i] <= x) i ++;
        if(i < j) nums[j --] = nums[i];
    }
    nums[i] = x;
    return i;
}

void quickSort(int nums[], int left, int right)
{
    if(left < right)
    {
        int p = partition(nums, left, right);
        quickSort(nums, left, p - 1);
        quickSort(nums, p + 1, right);
    }
    return;
}


int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++) cin >> nums[i];
    
    quickSort(nums, 0, n - 1);
    
    for(int i = 0;i < n;i ++) printf("%d ",nums[i]);
    return 0;
}