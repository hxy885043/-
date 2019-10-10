/*
面试题4：二维数组中的查找
题意：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
     请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
算法：单调性扫描
思路：每个子矩阵的右上角大于其所在行的所有数，小于其所在列的所有数，因此我们可以从右上角开始枚举
      其右上角枚举数为x:
      1）若x=target，找到目标值
      2）若x>target，其所在列的所有数都大于target，因此可以直接将该列剔除
      3）若x<target，其所在行的所有数都小于target，因此可以直接将该行剔除
时间复杂度：O(n + m)
空间复杂度：O(1)
*/

bool searchArray(vector<vector<int>> array, int target) {
    if(array.empty() || array[0].empty()) return false;
    int i = 0, j = array[0].size() - 1;
    while(i <= array.size() - 1 && j >= 0)
    {
    	if(array[i][j] == target) return true;
    	else if (array[i][j] > target) j --;
    	else i ++;
    }
    return false;
}