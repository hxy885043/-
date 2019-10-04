/*
Leetcode 76-最小覆盖子串
题意：给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
算法：滑动窗口
思路：两个指针出化都指向开头，然后right指着不断向右延伸，直到左右指针包含的滑动窗口的范围已包括了T的所有元素，然后
     left指针左移，直到不能包含T中所有元素为止，right指针移动到S末尾结束。采用哈希表来判断是否包括T中所有元素
*/


string minWindow(string s, string t) {
    int first = 0, last = 0, minLen = INT_MAX;
    int cnt = 0;

	// 字符串T的哈希表，记录每个字母出现的次数
	unordered_map<char, int> needs;
	// 滑动窗口的哈希表
	unordered_map<char, int> windows;

	for(int i = 0;i < t.size();i ++) needs[t[i]] ++;

	int left = 0,right = 0;
	while(right < s.size())
	{
		char c1 = s[right];
		if(needs.count(c1))
		{
			windows[c1] ++;
			if(windows[c1] == needs[c1])
				cnt++;
		}

        // left指针左移
		while(cnt == needs.size())
		{
			if(right - left < minLen){
				first = left;
				last = right;
				minLen = right - left + 1;
			}
			char c2 = s[left];
			if(needs.count(c2)){
				windows[c2] --;
				if(windows[c2] < needs[c2]) cnt --;
			}
			left ++;
		}
	    right ++;
	}
	if(minLen == INT_MAX) return "";
	return s.substr(first, minLen);
}
