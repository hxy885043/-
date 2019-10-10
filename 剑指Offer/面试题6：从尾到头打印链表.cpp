/*
面试题6：从尾到头打印链表
题意：输入一个链表的头结点，按照 从尾到头 的顺序返回节点的值。
算法：遍历链表
思路：先从前往后遍历一遍输入的链表，将结果记录在答案数组中。最后再将得到的数组逆序即可。
时间复杂度：O(n)
空间复杂度：O(1)

*/
vector<int> printListReversingly(ListNode* head) {
    vector<int> res;
    while(head)
    {
        res.push_back(head -> val);
        head = head -> next;
    }
    // vector的反向迭代器
    return vector<int>(res.rbegin(), res.rend());
}