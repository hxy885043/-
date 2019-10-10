/*
面试题5：替换空格
题意：请实现一个函数，把字符串中的每个空格替换成"%20"。
算法：双指针扫描
思路：1）遍历原数组，并根据空格个数求出最终的字符串长度
      2）使用两个指针，一个指针i指向原字符串末尾，另一个j指向最终字符串末尾
      3）两个指针都从后往前遍历，i遍历到空格时，指针j依次填充'0','2','%'
时间复杂度：O(n)
空间复杂度：O(1)
*/

string replaceSpaces(string &str) {
    int new_length = 0;
    for(int i = 0;i < str.size();i ++)
    {
    	if(str[i] == ' ')
    		new_length += 3;
    	else new_length += 1;
    }
    int i = str.size() - 1, j = new_length - 1;
    // 重新设置数组长度
    str.resize(new_length);

    while(i >= 0 && j >= 0)
    {
    	if(str[i] == ' ')
    	{
    		str[j --] = '0';
    		str[j --] = '2';
    		str[j --] = '%';
    	}
    	else str[j --] = str[i];
    	i --;
    }
    return str;
}