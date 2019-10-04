/*
Leetcode 155-最小栈
题意：设计一个支持push,top,pop操作，并能在常数时间内检索到最小值的栈
思路：设计两个栈，一个栈是正常的栈，另一个存储前i项的最小值，当取最小值时，可从该最小栈中提取元素
*/

stack<int> stk, stk_min;

MinStack() {
    
}
// 往两个栈中插入元素，最小值插入元素需要同栈顶元素进行比较
void push(int x) {
    stk.push(x);
    if(stk_min.empty()) stk_min.push(x);
    else stk_min.push(min(x, stk_min.top()));
    
}

// 两个栈同时进行删除
void pop() {
    stk.pop();
    stk_min.pop();
    
}

// 返回正常栈的栈顶元素
int top() {
    return stk.top();
}

// 返回最小栈中的栈顶元素
int getMin() {
    return stk_min.top();
}