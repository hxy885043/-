/*
Leetcode 105-从前序遍历和中序遍历构造二叉树
思路:递归构造
*/

unordered_map<int, int> hash;
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    // 将中序遍历每个数对应的下标存入哈希表，方便从根节点的值找到中序下标
    for(int i = 0;i < n;i ++) hash[inorder[i]] = i;
    return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
    
}

TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir)
{
    if(pl > pr) return NULL;
    int val = preorder[pl];
    int k = hash[val];
    int len = k - il;
    auto root = new TreeNode(val);
    root -> left = dfs(preorder, inorder, pl + 1, pl + len, il, k - 1);
    root -> right = dfs(preorder, inorder, pl + len + 1, pr, k + 1, ir);
    return root;
}