/*
单调栈：查找每个数左侧第一个比它小的数
单调队列：查找滑动窗口中的最值
*/

/*
Leetcode 84-柱状图中的最大面积
算法：单调栈
思路：枚举所有矩形的上边界，作为矩形的上边界。然后求出左右边界，即找出左边/右边离它最近的，且比它小的柱形
*/

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> stk;
    vector<int> left(n),right(n);
    
    // 单调栈找出每个数左边比它小的第一个数，若无，则编号为-1，保存到left数组中
    for(int i = 0;i < n;i ++)
    {
        while(!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
        if(stk.empty()) left[i] = -1;
        else left[i] = stk.top();
        stk.push(i);
    }

    // 单调栈找出每个数右边比它小的第一个数，若无，则变红为n，保存到right数组中
    stk = stack<int>();
    for(int i = n - 1;i >=0;i --)
    {
        while(!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
        if(stk.empty()) right[i] = n;
        else right[i] = stk.top();
        stk.push(i);
    }
    int res = 0;
    // 枚举每个上边界，计算左右边界的值。比较买诺记大小
    for(int i = 0;i < n;i ++) res = max(res, heights[i] * (right[i] - left[i] - 1));
    return res;
}