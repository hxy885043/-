/*
Leetcode 239-滑动窗口最大值
题意：给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。
      滑动窗口每次只向右移动一位。返回滑动窗口中的最大值。
算法：单调队列
思路：队列中保存的时距离当前数左边最大的一个数，因此对头就是最大数
*/
vector<int> maxSlidingWindow(vector<int>& nums,int k)
{
	vector<int> res;
	deque<int> q;

	for(int i = 0;i < nums.size();i ++)
	{
		if(q.size() && i - k + 1 > q.front()) q.pop_front();
		while(q.size() && nums[q.back()] <= nums[i]) q.pop_back();
		q.push_back(i);
		if(i >= k - 1) res.push_back(nums[q.front()]);
	}
	return res;
}