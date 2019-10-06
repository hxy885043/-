/*
Leetcode 94-二叉树的中序遍历
算法：栈
思路：先将所有左边的子节点推入栈中，然后弹出栈顶遍历该节点的所有右边节点
*/

vector<int> inorderTraversal(TreeNode* root) {
	TreeNode* p = root;
	stack<TreeNode*> stk;
	vector<int> res;

	while(p || !stk.empty())
	{
		while(p)
		{
			stk.push(p);
			p = p -> left;
		}
		if(!stk.empty())
		{
			p = stk.top();
			res.push_back(p -> val);
			stk.pop();
			p = p -> right;
		}
	}
	return res;
}