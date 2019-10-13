/*
面试题11： 旋转数组的最小数字
题意：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个升序的数组的一个旋转，输出旋转数组的最小元素。数组可能包含重复项。
算法：二分
思路：由于存在重复元素，数组开头和末尾可能会有形同元素，因此我们将数组末尾与开头的相同元素删去，为了可以用二分找最小值
时间复杂度：O(n)
*/

int findMin(vector<int>& nums) {
    int n = nums.size() - 1;
    if(n < 0) return -1;
    // 将数组末尾与开头相同的数字删去，便于应用二分性质
    while(n > 0 && nums[n] == nums[0]) n --;
    // 如果末尾大于等于开头的数字，说明数组是单调的，nums[0]即为最小值
    if(nums[n] >= nums[0]) return nums[0];
    int left = 0, right = n;
    while(left < right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] < nums[0]) right = mid;
        else left = mid + 1;
    }
    return nums[left];
}