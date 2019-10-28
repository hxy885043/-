/*
Leetcode 269-火星词典
题意：给定一个单词列表，该列表排列顺序按照新的字母顺序排列，求该新的字母顺序。
输入：["wrt","wrf","er","ett","rftt"]
输出："wertf"
算法：拓扑排序
思路：该题的难点在于如何构建图，将相邻的单词字符进行比较，只有第一个不同的字符才可以构建边，而单词内部是没有字典顺序的。同时还要注意去重多余的边。
*/

unordered_map<char, int> in;
unordered_map<char, unordered_set<char>> adj;
queue<char> q;
// 构建图 找到边
void init_graph(vector<string>& words)
{
    // 先需统计所有的点
    for(int i = 0;i < words[0].size();i ++){
        if(!in.count(words[0][i])){
            in[words[0][i]] = 0;
        }
    }
    
    for(int i = 0;i < words.size() - 1;i ++){
        // 每遍历一个字符串 都先将未出现过的点加入
        for(int j = 0;j < words[i + 1].size();j ++){
            if(!in.count(words[i + 1][j])){
                in[words[i + 1][j]] = 0;
            }
        }
        // 两相邻字符串一一比较，知道碰到不同字符为止
        for(int j = 0;j < words[i].size();j ++){
            char a = words[i][j], b = words[i + 1][j];
            if(a!=b){
                if(!adj[a].count(b)){
                    adj[a].insert(b);
                    in[b] ++;
                }
                break;
            }
        }
    }
}
// BFS拓扑排序
string topo_sort(){
    string res;
    for(auto p : in){
        if(p.second == 0) q.push(p.first);
    }
    
    while(!q.empty())
    {
        char t = q.front();
        q.pop();
        res += t;
        for(auto temp : adj[t]){
            in[temp] --;
            if(in[temp] == 0) q.push(temp);
        }
    }
    
    if(res.size() == in.size()) return res;
    else return "";
}

string alienOrder(vector<string>& words) {
    init_graph(words);
    return topo_sort();
}