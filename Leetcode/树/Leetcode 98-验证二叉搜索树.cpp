/*
Leetcode 98-验证二叉搜索树
题意：给定一个二叉树，判断其是否是一个有效的二叉搜索树。
算法：中序遍历
思路：中序遍历的二叉搜索树是从小到大排序的，因此只要判断中序遍历后的数是否递增
*/
bool isValidBST(TreeNode* root)
{
	if(root == NULL) return true;
	stack<TreeNode*> stk;
	TreeNode* pre = NULL;
	TreeNode* p = root;
	while(p || !stk.empty())
	{
		while(p)
		{
			stk.push(p);
			p = p -> left;
		}
		if(!s.empty())
		{
			p = stk.top();
			if(pre && pre -> val >= p -> val) return false;
			s.pop();
			pre = p;
			p = p -> right;
		}
	}
	return true;
}