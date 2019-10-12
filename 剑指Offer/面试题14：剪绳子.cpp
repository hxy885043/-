/*
面试题14：剪绳子
题意：把长为n的绳子剪成m段，求每段绳子之积的max
算法：动态规划
思路：当剪第一刀时，绳子的长度被分为两段，每段有n-1中可能，可通过f(n) = f(i) * f(i - j)来遍历长度求最大值
时间复杂度：O(n^2)
*/
int maxProductAfterCutting(int length) {
    if(length <= 1) return 0;
    if(length == 2) return 1;
    if(length == 3) return 2;
    vector<int> products(length + 1, 0);
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;
    for(int i = 4;i <= length;i ++)
    {
        for(int j = 1;j <= i / 2;j ++)
        {
            products[i] = max(products[i], products[j] * products[i - j]);
        }
    }
    return products[length];
}