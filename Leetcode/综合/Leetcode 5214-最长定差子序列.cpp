/*
Leetcode 5214-最长定差子序列
题意：给你一个整数数组 arr 和一个整数 difference，请你找出 arr 中所有相邻元素之间的差等于给定 difference 的等差子序列，并返回其中最长的等差子序列的长度。
算法：动态规划/哈希
思路：采用最长上升子序列的动态规划方法会超时，注意到数与数之间差一定，因此一个数确定了，它前面的那个数也是确定的
      因此可以采用哈希来存储每个数及小标，当查询前一个数时直接从哈希表中国查询。
*/
int longestSubsequence(vector<int>& arr, int difference) {
    int n = arr.size();
    vector<int> dp(n);
    unordered_map<int, int> hash;
    int res = 1;
    for(int i = 0;i < arr.size();i ++)
    {
        dp[i] = 1;
        int temp = arr[i] - difference;
        if(hash.count(temp))
        {
            dp[i] = max(dp[i], dp[hash[temp]] + 1);
            res = max(dp[i], res);
        }
        hash[arr[i]] = i;
    }
    return res;
}