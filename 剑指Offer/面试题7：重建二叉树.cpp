/*
面试题7：重建二叉树
题意：输入一棵二叉树前序遍历和中序遍历的结果，请重建该二叉树。
算法：递归
思路：1）利用前序遍历找根节点，即前序遍历的第一个值就是根节点的值
      2）利用中序遍历找左右子树，通过前序遍历的第一个值找到中序遍历该值的下标,其左边为左子树，右边为右子树
      3）通过中序遍历划分出来的左右子树个数找前序遍历的左右子树，假设中序遍历的找到的左子树个数为l，则前序
      遍历根节点后面l个数时左子树，其余后面的数为右子树
      4）递归构造左右子树
时间复杂度：O(n)
*/

// 记录中序遍历每个值对应的下标
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