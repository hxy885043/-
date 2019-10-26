/*
堆排序：
题意：通过堆排序输出前m个最小值
思路：通过构建小顶堆依次输出前m个小值
      1）将无序列表构建成小顶堆，堆顶为最小元素
      2) 输出堆顶元素，将数组最后一位数字放到堆顶，并进行更新
      3）重复2多次，直至输出m个最小数字
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int nums[N];

void adjustHeap(int u, int size)
{
    // u记录原来的下标, t记录可能需要交换的下标，若不交换，则t=u
    int t = u;
    if(2*u < size && nums[2*u] < nums[t]) t = 2 * u;
    if(2*u+1 < size && nums[2*u+1] < nums[t]) t = 2 * u + 1;
    
    if(t!=u)
    {
        swap(nums[t], nums[u]);
        adjustHeap(t, size);
    }
    return;
}
int main()
{
    int m,n;
    cin >> n >> m;
    for(int i = 0;i < n;i ++) cin >> nums[i];
    
    // 建堆
    for(int i = n/2;i >= 0;i --)
    {
        adjustHeap(i, n);
    }
    
    int len = n - 1;
    
    for(int i = 0;i < m;i ++)
    {
        cout << nums[0] << " ";
        nums[0] = nums[len];
        adjustHeap(0, len);
        len --;
    }
    return 0;
}