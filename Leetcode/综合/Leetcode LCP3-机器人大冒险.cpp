/*
Leetcode LCP3-机器人大冒险
题意：扣团队买了一个可编程机器人，机器人初始位置在原点(0, 0)。小伙伴事先给机器人输入一串指令command，机器人就会无限循环这条指令的步骤进行移动。指令有两种：
    U: 向y轴正方向移动一格；R: 向x轴正方向移动一格。不幸的是，在 xy 平面上还有一些障碍物，他们的坐标用obstacles表示。机器人一旦碰到障碍物就会被损毁。
    给定终点坐标(x, y)，返回机器人能否完好地到达终点。如果能，返回true；否则返回false。
算法：模拟
思路：暴力法会超时，由于是路径是循环走的，因此我们可以找到最后一次循环的起点，从该起点进行一次遍历command,可以判断终点是否在路径上，判断obstacles也是一样
     只不过需要判断障碍物是否在终点之前
*/

int n, m;
int xx, yy;

bool isToEnd(string &command, int x, int y)
{
    int t = min(x / xx, y / yy);
    // 将t_x,t_y当作新的起点
    int t_x = t * xx, t_y = t * yy;
    if(t_x == x && t_y == y) return true;
    for(int i = 0;i < m;i ++)
    {
        if(command[i] == 'U') t_y ++;
        if(command[i] == 'R') t_x ++;
        if(t_x == x && t_y == y) return true;
    }
    return false;
}

bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
    m = command.size();
    n = obstacles.size();
    xx = 0, yy = 0;
    for(int i = 0;i < m;i ++)
    {
        if(command[i] == 'U') yy ++;
        if(command[i] == 'R') xx ++;
    }
    
    if(!isToEnd(command, x, y)) return false;
    for(int i = 0;i < n;i ++)
    {
        int o_x = obstacles[i][0], o_y = obstacles[i][1];
        if(o_x <= x && o_y <= y)
        {
            if(isToEnd(command, o_x, o_y)) return false;
        }
    }
    return true;
}




/*
此处做了一些优化，将路径保存在set容器中，可以直接查找最后一次循环的路径是否在set容器中来判断是否能走到终点
unordered_set底层实现是哈希表，insert,find都是O(1)
*/
int n, m;
int xx, yy;
set<pair<int, int>> s;
bool isToEnd(string &command, int x, int y)
{
    int t = min(x / xx, y / yy);
    int t_x = x - t * xx, t_y = y - t * yy;
    if(t_x == 0 && t_y == 0) return true;
    if(s.find({t_x, t_y})!= s.end()) return true;
    return false;
}

bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
    m = command.size();
    n = obstacles.size();
    xx = 0, yy = 0;
    for(int i = 0;i < m;i ++)
    {
        if(command[i] == 'U') yy ++;
        if(command[i] == 'R') xx ++;
        s.insert({xx, yy});
    }
    
    if(!isToEnd(command, x, y)) return false;
    for(int i = 0;i < n;i ++)
    {
        int o_x = obstacles[i][0], o_y = obstacles[i][1];
        if(o_x <= x && o_y <= y)
        {
            if(isToEnd(command, o_x, o_y)) return false;
        }
    }
    return true;
}