/*
Leetcode 860-柠檬水找零
题意：在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
     每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
     注意，一开始你手头没有任何零钱。如果你能给每位顾客正确找零，返回 true ，否则返回 false 。
算法：贪心
思路：10块钱找钱只有5元一种，20找钱有两种一种是10+5，另一种位5 + 5 + 5，因此在找20的时候，若有10+5组合先找10+5，若没有再找3张5元，目的
      是为了防止10元找钱没有5元可找，因此需尽可能的保留5元。
*/

bool lemonadeChange(vector<int>& bills) {
    int fives = 0, tens = 0;
    for(int i = 0;i < bills.size();i ++)
    {
        if(bills[i] == 5) fives ++;
        else if(bills[i] == 10)
        {
            tens ++;
            if(fives) fives --;
            else return false;
        }
        else if(bills[i] == 20)
        {
            int t = 15;
            if(t && tens)
            {
                t -= 10;
                tens --;
            }
            while(t && fives)
            {
                t -= 5;
                fives --;
            }
            if(t) return false;
            
        }
    }
    return true;
}