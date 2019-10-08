/*
Leetcode LCP4-覆盖
题意：你有一块棋盘，棋盘上有一些格子已经坏掉了。你还有无穷块大小为1 * 2的多米诺骨牌，你想把这些骨牌不重叠地覆盖在完好的格子上，
     请找出你最多能在棋盘上放多少块骨牌？这些骨牌可以横着或者竖着放。
算法：二分图的最大匹配
思路：可以对棋盘进行黑白染色，使得任意两个格子的颜色不同，因此这个棋盘可以看作二分图，横纵坐标之和为奇数的在一个
      集合，横纵坐标为偶数在一个集合，通过匈牙利算法可算出该二分图的最大匹配。要记得跳过损坏的各自。
。
*/
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int broke_flag[9][9];
int visited[9][9];
int match[81];
int n1, m1;
int domino(int n, int m, vector<vector<int>>& broken) {
    n1 = n, m1 = m;
    for(int i = 0;i < broken.size();i ++)
    {
        int a = broken[i][0], b = broken[i][1];
        broke_flag[a][b] = 1;
    }
    memset(match, -1, sizeof match);
    int res = 0;
    
    for(int i = 0;i < n;i ++)
        for(int j = 0;j < m;j ++)
        {
            // if(!(i + j) % 2||broke_flag[i][j] ) continue;
            memset(visited, 0, sizeof visited);
            if(!broke_flag[i][j] && !((i + j) % 2) && dfs(i, j))
                res ++;
        }
    return res;
}

bool dfs(int x, int y)
{
    for(int i = 0;i < 4;i ++)
    {
        int a = x + dx[i], b = y + dy[i];
        if(a >= n1 || a < 0 || b >= m1 || b < 0 || broke_flag[a][b])
            continue;
        int temp = a * m1 + b;
        if(!visited[a][b])
        {
            visited[a][b] = 1;
            if(match[temp] == -1 || dfs(match[temp] / m1, match[temp] % m1))
            {
                match[temp] = x * m1 + y;
                return true;
            } 
        }
    }
    return false;
}