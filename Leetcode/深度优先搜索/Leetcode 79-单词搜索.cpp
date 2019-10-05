/*
Leetcode 79-单词搜索
题意：给定一个二维网格和一个单词，找出该单词是否存在于网格中。“相邻”单元格是那些水平相邻或垂直相邻的单元格。
算法：DFS
思路：首先枚举起点，从起点开始，依次搜索下一个点的位置，在枚举的过程中，要保证目标单词匹配
时间复杂度：O(nm * 3^k)
*/

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
int n, m;
bool exist(vector<vector<char>>& board, string word) {
    n = board.size();
    m = board[0].size();
    
    if(n == 0 || m == 0) return false;
    
    for(int i = 0;i < n;i ++)
        for(int j = 0;j < m;j ++)
            if(dfs(board, i, j, word, 0)) return true;
    return false;
}
bool dfs(vector<vector<char>>& board, int x, int y, string &word, int u)
{
    if(board[x][y] != word[u]) return false;
    if(u == word.size() - 1) return true;
    
    board[x][y] = '.';
    for(int i = 0;i < 4;i ++)
    {
        int a = x + dx[i], b = y + dy[i];
        if(a >= 0 && a < n && b >= 0 && b < m)
            if(dfs(board, a, b, word, u + 1))
                return true;
    }
    board[x][y] = word[u];
    return false;
    }