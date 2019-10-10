/*
面试题3 - 1：数组中重复的数字
题意：给定一个数组nums，长度为n，其数值范围在0-n-1之间，其中可能存在重复数字，求返回任意一个重复数字
算法：数组遍历
思路：注意题中的条件每个数值范围都在0-n-1之间，也就是说当把nums数组重新排序之后，下标i上的数字应是i,若有重复数字，
      则下标i上的数字不止一个。因此我们设法将每个数放到其对应的位置上（即nums[i] = i）。
      在遍历每一个数字nums[i]时，判断该数字与下标是否相等，若不相等，我们将nums[i]作为下标，去看nums[nums[i]]
      的值是否与nums[i]相等，若相等，则找到了一个重复数字，若不相等，通过交换将nums[i]放置正确的位置上。
时间复杂度：O(n)
空间复杂度：O(1)
*/

int duplicateInArray(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0;i < n;i ++)
    {
        // 若nums[i]的内容超出数组范围限制 返回-1
        if(nums[i] < 0 || nums[i] > n - 1) return -1;
    }
    for(int i = 0;i < n;i ++)
    {
        // 当nums[i]与其当前下标i不相等 需要通过交换操作将nums[i]放到下标为nums[i]的位置上
        while(nums[i] != i)
        {
            if(nums[nums[i]] != nums[i])
            {
                swap(nums[i], nums[nums[i]]);
            }
            else return nums[i];
        }
    }
    return -1;
}


/*
面试题3 - 2：不修改数组找出重复的数字
题意：给定一个数组nums，长度为n + 1，其数值范围在1-n之间，至少有一个重复数字，但不能修改数组，求返回任意一个重复数字
算法：二分
思路：由于数值范围在1-n之间，因此当我们把数值范围划分两个区间[1, mid],[mid+1, n]之间，分别统计这两个区间的个数，注意
      区间范围是指数值的范围，区间个数是指在数组中该区间所有数出现次数之和。至少有一个重复数字，因此这两个区间一定有一个
      区间的个数大于其区间长度。再对这个区间进行二分，重复上述操作，直至只剩一个数，则该数就是一个重复数。
时间复杂度：O(nlogn)
空间复杂度：O(1)
*/
int duplicateInArray(vector<int>& nums) {
    int left = 1, right = nums.size() - 1;
    while(left < right)
    {
        int mid = (left + right) / 2;
        // 记录nums数组在左边区间的个数
        int count = 0;
        for(int i = 0;i < nums.size();i ++)
        {
            if(nums[i] >= nums[left] && nums[i] <= nums[mid]) count ++;
        }
        if(count > mid - left + 1) right = mid;
        else left = mid + 1;
    }
    return nums[left];
}