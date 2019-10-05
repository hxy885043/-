/*
Leetcode 46-全排列
题意：给定一个没有重复数字的序列，返回其所有可能的全排列。
算法：DFS
思路：枚举每个位置上放哪个数
*/

int n;
vector<int> path;
vector<vector<int>> res;
vector<bool> st;

vector<vector<int>> permute(vector<int>& nums) {
    n = nums.size();
    st = vector<bool>(n);       
    dfs(nums, 0);
    return res;
}

// 遍历每个位置
void dfs(vector<int>& nums, int u)
{
    if(u == n)
    {
        res.push_back(path);
        return;
    }
    
    for(int i = 0;i < n;i ++)
    {
        if(!st[i])
        {
            st[i] = true;
            path.push_back(nums[i]);
            dfs(nums, u + 1);
            path.pop_back();
            st[i] = false;
        }
    }
}