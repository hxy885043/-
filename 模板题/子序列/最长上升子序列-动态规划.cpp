/*
最长上升子序列：求单调递增的子序列的最长长度
思路一：动态规划，dp[i]数组表示以nums[i]为结尾的所有上升子序列中的最大长度，
       状态转移方程：if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1) j∈(0,i - 1);
       假定一个子序列的最后一个数是nums[i],从nums[0]遍历到nums[i - 1]寻找倒数第二个数，即比nums[i]小的数，并将其对应
       的dp值取出后加上1就是以nums[i]为结尾的上升子序列的一种可能长度，将不同的可能长度比较选择最长的。
复杂度：O(n^2)
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int dp[N];
int nums[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        cin >> nums[i];
    }
    int res = 0;

    for(int i = 0;i < n;i ++)
    {
        dp[i] = 1;
        for(int j = 0;j < i;j ++)
        {
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i], dp[j] + 1);
                res = max(res, dp[i]);
            }
        }
    }
    printf("%d\n", res);
    return 0;
}

/*
最长上升子序列：求单调递增的子序列的最长长度
思路二：动态规划，dp[i]数组表示长度为i+1的的子序列中末尾数最小的数
       状态转移：遍历每一个数nums[i]，若该数大于当前最大长度的末尾最小数(dp[cnt - 1])，则需要增加长度以存放nums[i]
       否则，需要将nums[i]替换到某一个长度的dp中去，由于dp[i]是单调递增序列，通过二分法可以查找大于等于nums[i]的第一个数
复杂度：O(nlogn)
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
int dp[N];
int nums[N];
int n, cnt;

int main()
{
    cin >> n;

    for(int i = 0;i < n;i ++)
    {
        cin >> nums[i];
    }

    dp[cnt ++] = nums[0];
    for(int i = 1;i < n;i ++)
    {
        if(nums[i] > dp[cnt - 1]) dp[cnt ++] = nums[i];
        else
        {
            int left = 0, right = cnt - 1;
            while(left < right)
            {
                int mid = (left + right) / 2;
                if(dp[mid] >= nums[i]) right = mid;
                else left = mid + 1;
            }
            dp[left] = nums[i];
        }
    }
    printf("%d\n",cnt);
    return 0;
}