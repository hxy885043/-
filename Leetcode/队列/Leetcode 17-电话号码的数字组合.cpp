/*
Leetcode 17-电话号码的数字组合
题意:给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。数字到字母的映射与电话按键相同。
算法：队列
思路：用哈希表存储数字到字母的映射，每遍历一个数字，则队列中的每个字符串都要加上该数字映射的每个字母。
*/
vector<string> letterCombinations(string digits){
    int n = digits.size();     
    queue<string> q;
    vector<string> res;
    if(n == 0) return res;

    unordered_map<char, string> hash = {
      {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, 
      {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"},
      {'8',"tuv"}, {'9',"wxyz"}};                                             
    
    q.push("");
    for(int i = 0;i < n;i ++)
    {
      // 对每个长度为i的字符串后加上digits[i]映射的每个数
      while(q.front().length() == i)
      { 
          // 从队头读取字符串并弹出
          string now = hash[digits[i]];
          string t = q.front();
          q.pop();
          // 加上digits[i]映射的字母，并加入队列中
          for(int j = 0;j < hash[digits[i]].size();j ++)
          {
              q.push(t + now[j]);
          }
      }
    }
    while(!q.empty())
    {
        res.push_back(q.front());
        q.pop();
    }
    return res;
}