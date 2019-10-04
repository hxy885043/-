/*
Leetcode 167-两数之和Ⅱ 输入有序数组
题意：给定一个已按照升序排列的有序数组，找到两个数使得它们相加之和等于目标数，函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
算法：双指针
思路：一个指针指向数组开头，一个指针指向数组结尾，若两个指针对应数之和等于target,则返回，若大于target，则尾指针向前移动，
     若小于target，则头指针向后移动
复杂度：O(n)
*/
vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    vector<int> res;
    while(left < right)
    {
        int sum = numbers[left] + numbers[right];
        if(sum == target){
            res.push_back(left + 1);
            res.push_back(right + 1); 
            break;
        }
        else if (sum > target) right --;
        else left ++;
    }
    return res;
    
}
