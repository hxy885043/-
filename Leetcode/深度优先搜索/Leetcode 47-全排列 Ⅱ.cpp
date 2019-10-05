/*
Leetcode 47-全排列 Ⅱ
题意：给定一个可包含重复数字的序列，返回所有不重复的全排列。
算法：DFS
思路：该题需要注意去重，去重可以对数组进行排序，将所有相同数字放在一起，同时在进行DFS时需要与前一个数比较，若相同且未访问过则需跳过
*/

int n;
vector<int> path;
vector<vector<int>> res;
vector<bool> st;
vector<vector<int>> permuteUnique(vector<int>& nums) {
    n = nums.size();
    sort(nums.begin(), nums.end());
    st = vector<bool>(n);       
    dfs(nums, 0);
    return res;
}

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
            if(i >= 1 && nums[i] == nums[i - 1] && st[i - 1] != 0) continue; // 去重
            st[i] = true;
            path.push_back(nums[i]);
            dfs(nums, u + 1);
            path.pop_back();
            st[i] = false;
        }
    }
}  