/*
Leetcode 1220-统计元音字母序列的数目
题意：你一个整数 n，请你帮忙统计一下我们可以按下述规则形成多少个长度为 n 的字符串：
	字符串中的每个字符都应当是小写元音字母（'a', 'e', 'i', 'o', 'u'）
	每个元音 'a' 后面都只能跟着 'e'
	每个元音 'e' 后面只能跟着 'a' 或者是 'i'
	每个元音 'i' 后面 不能 再跟着另一个 'i'
	每个元音 'o' 后面只能跟着 'i' 或者是 'u'
	每个元音 'u' 后面只能跟着 'a'
    由于答案可能会很大，所以请你返回 模 10^9 + 7 之后的结果。
算法：迭代
思路：每一次迭代时，以a开头的字符串个数等于上一次迭代时以e开头的字符串个数，即na[k] = ne[k - 1],同理其他字母也一样
*/

int countVowelPermutation(int n) {
    long long nna, nne, nni, nno, nnu;
    long long mod = 1e9 + 7;
    long long na = 1, ne = 1, ni = 1, no = 1, nu = 1;
    for(int i = 2;i <= n;i ++)
    {
        nna = ne;
        nne = (na + ni) % mod;
        nni = (na + ne +no +nu) % mod;
        nno = (ni + nu) % mod;
        nnu = na;
        
        na = nna;
        ne = nne;
        ni = nni;
        no = nno;
        nu = nnu;
    }
    return (na + ne + ni + no + nu)%mod;
}