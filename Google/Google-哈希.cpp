/*
C++字符串处理：
cin : 遇空格、Tab、回车结束，且不保存结束符，结束符还在缓存中
cin.get(字符数组名，接收长度，结束符) ： 其中结束符意味着遇到该符号结束字符串读取,默认为ENTER，cin.get()操作遇到结束符停止读取，但并不会将结束符从缓冲区丢弃。
cin.get() 可以读入一个换行符
string 头文件中的getline : 读入一整行的字符串包括空格，getline(cin, string)，会将换行符从缓存中删去
输出string类型的字符串： s.c_str()
*/

/*
哈希迭代器正向迭代：hash.begin(),hash.end(),iterator;反向迭代器：hash.rbegin(),hash,rend(),reverse_iterator;
*/

/*
Google Kickstart2016 Round A Problem A-国家领导人
*/
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

const int N = 1010;
bool visited[26];

int main()
{
    int T;
    cin >> T;
    for(int cases = 1;cases <= T;cases ++)
    {
        int n;
        cin >> n;
        map<int, vector<string>> hash;
        cin.get();
        for(int i = 0;i < n;i ++)
        {
            string s;
            getline(cin, s);
            memset(visited, 0, sizeof visited);
            
            int count = 0;
            
            for(int i = 0;i < s.size();i ++)
            {
                if(s[i] == ' ') continue;
                if(!visited[s[i] - 'A']) {visited[s[i] - 'A'] = 1; count ++;}
            }
            hash[count].push_back(s);
        }
        map<int, vector<string>>::reverse_iterator it = hash.rbegin();
        vector<string> t = it -> second;

        if(t.size() > 1)
        {
            sort(t.begin(), t.end());
            
        }
        printf("Case #%d: %s\n",cases, t[0].c_str());
    }
    return 0;
}