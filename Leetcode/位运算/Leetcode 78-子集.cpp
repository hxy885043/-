/*
Leetcode 78-子集
题意：给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
算法：位运算
思路：用0，1表示每个数选与不选的情况，所有的情况可以用0-2^n二进制来表示，因此只要找出每个二进制中为1的数
*/
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    // 1 << nums.size()表示2^n
    for(int i = 0;i < 1 << nums.size();i ++)
    {
    	vector<int> now;
    	for(int j = 0;j < nums.size();j ++)
    		// 查找某个数的二进制是1的位数
    		if(i >> j & 1) now.push_back(nums[j]);
    	res.push_back(now);
    }
    return res;
}