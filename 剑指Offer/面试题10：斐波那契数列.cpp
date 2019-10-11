/*
面试题10：斐波那契数列 
题意：输入一个整数n，求斐波那契数列的第n项
算法：递推
思路：用两个变量滚动往后计算，a表示第n - 1项，b表示第n项，c表示第n + 1项
时间复杂度：O(n)
*/

int Fibonacci(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    
    int a = 0, b = 1;
    int c = 0;
    for(int i = 2;i <= n;i ++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}