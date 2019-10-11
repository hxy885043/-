/*
面试题9：用两个栈实现队列
题意：请用栈实现一个队列，支持如下四种操作：pop,push,peek,empty
算法：模拟
思路：一个栈存放数据，另一个栈做辅助栈，当进行pop操作时，将所有的元素从主栈中弹出，压入辅助栈，并弹出辅助栈的栈顶，也就是队列的
     第一个元素，然后又把辅助栈的全部元素压入主栈，peek同理。
时间复杂度：O(n)
*/

stack<int> stk, cache;
/** Initialize your data structure here. */
MyQueue() {
    
}

/** Push element x to the back of queue. */
void push(int x) {
    stk.push(x);
}

/** Removes the element from in front of queue and returns that element. */
int pop() {
    while(stk.size()){
        cache.push(stk.top());
        stk.pop();
    }
    int t = cache.top();
    cache.pop();
    while(cache.size())
    {
        stk.push(cache.top());
        cache.pop();
    }
    return t;
    
}

/** Get the front element. */
int peek() {
    while(stk.size()){
        cache.push(stk.top());
        stk.pop();
    }
    int t = cache.top();
    while(cache.size())
    {
        stk.push(cache.top());
        cache.pop();
    }
    return t;
}

/** Returns whether the queue is empty. */
bool empty() {
    return stk.empty();
}
