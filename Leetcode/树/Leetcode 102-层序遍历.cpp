/*
Leetcode 102-层序遍历
算法：队列（BFS）
*/
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> res;
	vector<int> temp;
	if(!root) return res;
	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty())
	{
	    int len = q.size();
	    
	    temp.clear();
	    for(int i = 0;i < len;i ++)
	    {
	        temp.push_back(q.front() -> val);
	        if(q.front() -> left) q.push(q.front() -> left);
	        if(q.front() -> right) q.push(q.front() -> right);
	        q.pop();
	    }
	    res.push_back(temp);
	}
	return res;
}