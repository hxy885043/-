/*
面试题13：机器人的运动范围
题意：有一个m*n的矩阵，一个机器人从（0，0）开始移动，可以上下左右和移动，但不能进入横纵坐标数位之和大于k的各自，问机器人可以到达多少个方格
算法：BFS/DFS
思路：利用深搜或者宽搜遍历每一个点，并在遍历时判断条件是否成立
时间复杂度：O(m*n)
*/

int getNum(int x)
{
    int res = 0;
    while(x)
    {
        res += x % 10;
        x = x / 10;
    }
    return res;
}
int movingCount(int threshold, int rows, int cols)
{
    if(!rows || !cols) return 0;
    vector<vector<bool>> st(rows, vector<bool>(cols));
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    int res = 0;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(getNum(x) + getNum(y) > threshold || st[x][y]) continue;
        st[x][y] = 1;
        res ++;
        for(int i = 0;i < 4;i ++)
        {
            int a = x + dx[i], b = y + dy[i];
            if(a >= rows || a < 0 || b >= cols || b < 0) continue;
            q.push({a, b});
        }
    }
    return res;
}