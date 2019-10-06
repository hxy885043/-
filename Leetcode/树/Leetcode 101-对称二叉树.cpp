/*
Leetcode 101-对阵二叉树
题意：给定一个二叉树，检查它是否是镜像对称的。
算法：递归、迭代
思路：递归：左右对称-两根节点的值要相等；左边的左子树和右边的右子树；左边的右子树和右边的左子树
      迭代：左边树左中右遍历，右边右中左遍历
*/
// 递归写法
bool isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    return dfs(root -> left, root -> right);
}

bool dfs(TreeNode* p,TreeNode* q)
{
	if(p == NULL && q == NULL) return true;
	if(p == NULL || q == NULL) return false;
	return (p -> val == q -> val) && dfs(p -> left, q -> right) && dfs(p -> right, q -> left);
}


// 迭代写法
bool isSymmetric(TreeNode* root) {
	if(root == NULL) return true;
	stack<TreeNode*> left, right;
	TreeNode* l = root -> left, r = root -> right;
	while(l || r || left.size() || right.size())
	{
		while(l && r)
		{
			left.push(l);l = l -> left;
			right.push(r);r = r -> right;
		}
		if(l || r) return false;

		if(left.size() && right.size())
		{
			l = left.top();left.pop();
			r = right.top();right.pop();
			if(l -> val != r -> val) return false;
			l = l -> right;
			r = r -> left;
		}
	}
	return true;
}