/*
Google Kickstart2018 Round C Problem A-行星距离
思路：首先通过dfs寻找环，用栈记录已访问过的节点，若再次访问到该节点，则可认为找到栈，同时要避免找到父节点的情况，
对于环上的每个节点，通过dfs记录每个与它相连节点的深度
*/
#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

const int N = 1010;

vector<vector<int>> matrix(N);
stack<int> path;
vector<int> circ;

bool visited[N];
int d[N];

bool dfs(int p, int father)
{
    visited[p] = 1;
    path.push(p);
    //cout << p << endl;
    
    for(int i = 0;i < matrix[p].size();i ++)
    {
        int temp = matrix[p][i];
        if(temp != father)
        {
            if(visited[temp])
            {
                circ.push_back(temp);
                while(path.top()!=temp)
                {
                    circ.push_back(path.top());
                    path.pop();
                }
                return true;
            }
            if(dfs(temp, p)) return true;
        }
    }
    path.pop();
    return false;
}


void dfs_depth(int p, int depth)
{
    visited[p] = 1;
    d[p] = depth;
    
    for(int i = 0;i < matrix[p].size();i ++)
    {
        int temp = matrix[p][i];
        if(!visited[temp]) dfs_depth(temp, depth + 1);
    }
    
}

int main()
{
    int T;
    cin >> T;
    for(int cases = 1;cases <= T;cases ++)
    {
        int n;
        cin >> n;
        
        path = stack<int>();
        for(int i = 0;i < matrix.size();i ++) matrix[i].clear();
        memset(visited, 0, sizeof visited);
        circ.clear();
        
        for(int i = 0;i < n;i ++)
        {
            int a, b;
            cin >> a >> b;
            matrix[a].push_back(b);
            matrix[b].push_back(a);
        }
        
        dfs(1, -1);
        
        //for(int i = 0;i < circ.size();i ++) cout << circ[i] << endl;
        
        memset(visited, 0, sizeof visited);
        memset(d, 0, sizeof d);
        
        for(int i = 0;i < circ.size();i ++) visited[circ[i]] = 1;
        for(int i = 0;i < circ.size();i ++) dfs_depth(circ[i], 0);
        
        printf("Case #%d:", cases);
        for(int i = 1;i <= n;i ++) printf(" %d",d[i]);
        puts("");
    }
    return 0;
}

/*
字符串的输入与输出：
scanf: 遇空格、Tab、回车结束
cin : 遇空格、Tab、回车结束
gets : 读取到换行符结束 ，但换行符会被丢弃，在末尾加'\0'
puts : 在输出字符串后回车
getline:接受包括空格的字符串

*/