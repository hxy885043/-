/*
Leetcode 90-子集Ⅱ
题意：给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）
算法：DFS
思路：同全排列思路一样注意排序后去重
*/
vector<vector<int>> res;
vector<int> path;

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    dfs(nums, 0);
    return res;
}
void dfs(vector<int> &nums, int u)
{
    res.push_back(path);
    for(int i = u;i < nums.size();i ++)
    {
        if(i > u && nums[i] == nums[i - 1]) continue;
        path.push_back(nums[i]);
        dfs(nums,i + 1);
        path.pop_back();
    }
}