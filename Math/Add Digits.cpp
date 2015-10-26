/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/

/*
O(N^2)不难吧- -。。大水。。注意while的条件
O(1)。。需要一点数学知识。。https://en.wikipedia.org/wiki/Digital_root
代码贴在后面吧。。。
*/

class Solution {
public:
    int addDigits(int num) {
        int ans = 0;
        while(num>=10){
            ans=0;
            while(num>=10){
                ans+=(num%10);
                num/=10;
            }
            ans+=num;
            num=ans;
        }
        return num;
    }
};


//数学知识版
public class Solution {
    public int addDigits(int num) {
        return num - 9 * ((num - 1) / 9);
    }
}
