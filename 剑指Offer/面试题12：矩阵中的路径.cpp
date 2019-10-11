/*
面试题12：矩阵中的路径
题意：判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
      如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。
算法：DFS
思路：枚举每个起点从每个起点开始沿三个方向DFS遍历下去
时间复杂度：O(n^2*3^k)

*/
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int n, m;
bool hasPath(vector<vector<char>>& matrix, string str) {
    if(!matrix.size() || !matrix[0].size()) return false;
    n = matrix.size();
    m = matrix[0].size();
    for(int i = 0;i < matrix.size();i ++){
        for(int j = 0;j < matrix[0].size();j ++){
            if(dfs(matrix, str, i, j, 0)) return true;
        }
    }
    return false;
}

bool dfs(vector<vector<char>>& matrix, string &str, int i, int j, int u)
{
    if(matrix[i][j] != str[u]) return false;
    if(matrix[i][j] == str[u] && u == str.size() - 1) return true;
    char c = matrix[i][j];
    matrix[i][j] = '#';
    for(int k = 0;k < 4;k ++)
    {
        int x = i + dx[k],y = j + dy[k];
        if(x < 0 || x >= n || y < 0 || y >= m) continue;
        if(dfs(matrix, str, x,  y, u + 1)) return true;
    }
    matrix[i][j] = c;
    return false;
}