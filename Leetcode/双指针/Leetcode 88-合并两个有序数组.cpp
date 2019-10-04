/*
Leetcode 88-合并两个有序数组
题意：给定两个有序整数数组nums1和nums2，将nums2合并到nums1中，使得num1成为一个有序数组
算法：双指针
思路：合并到nums1中，且nums1有足够空间，因此一个指针指向nums1的末尾，一个指向nums2的末尾，两个指针
      所对应的数哪个大，将其放置到nums1数组的末尾，并将该指针向前移，不断比较移动指针，直至nums2指
      针已到达开头前一位。
*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int t = m + n - 1;
    int i = m - 1;
    int j = n - 1;
    while(i >=0 && j >= 0)
    {
        if(nums1[i] > nums2[j])
        {
            nums1[t--] = nums1[i--];
        }
        else
        {
            nums1[t--] = nums2[j--];
        }
        
    }
    while(j >= 0) nums1[t --] = nums2[j--];
    return;
}