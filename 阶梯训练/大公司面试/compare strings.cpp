/*
比较两个字符串A和B，确定A中是否包含B中所有的字符。字符串A和B中的字符都是 大写字母
样例
给出 A = "ABCD" B = "ACD"，返回 true
给出 A = "ABCD" B = "AABC"， 返回 false
注意
在 A 中出现的 B 字符串里的字符不需要连续或者有序。
*/

//1 不能直接用find，因为B中可能会有重复字符,解决这个问题就是B里面一个字母在A中找到就删除。
//2 还要注意判断A如果为空字符串，则直接判断false，否则利用find+erase的算法会出问题。

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
    if(A.size()<B.size()){
        if(A.size()==0) return false;
        string C=A;
        A=B;
        B=C;
    }
    for(int j=0;j<B.size();j++){
        if(A.find(B[j])!=A.npos){
            A.erase(A.begin()+A.find(B[j]));
        }else{
            return false;
        }
    }
    return true;
    }
};

