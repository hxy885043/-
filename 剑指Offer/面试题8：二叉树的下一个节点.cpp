/*
面试题8：二叉树的下一个节点 
题意：给定一棵二叉树的其中一个节点，请找出中序遍历序列的下一个节点。树中节点还有一个指向父节点的指针
算法：模拟
思路：1）如果该节点有右子树，右子树最左边的节点为其后继节点
      2）如果该节点没有右子树，那么向上寻找father节点，找到第一个是father左儿子的节点，则其father节点为其后继
时间复杂度：O(h)

*/
TreeNode* inorderSuccessor(TreeNode* p) {
    if(p -> right){
        p = p -> right;
        while(p -> left) p = p -> left;
        return p;
    }
    
    while(p -> father && p == p -> father -> right) p = p -> father;
    return p -> father;
}