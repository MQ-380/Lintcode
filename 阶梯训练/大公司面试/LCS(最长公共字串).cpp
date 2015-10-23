/*
给出两个字符串，找到最长公共子串，并返回其长度。
样例
给出A=“ABCD”，B=“CBCE”，返回 2
注意
子串的字符应该连续的出现在原字符串中，这与子序列有所不同。
*/

//循环两次，每次加上一个字符对比，O（n^2）
//应该能有更好的算法。。。

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        int ans=0,tmp;
        for(int j=0;j<B.size();j++){
            string c="";
            for(int k=0;k<B.size()-j;k++){
                c+=B[j+k];
                if(A.find(c)!=A.npos && c.size()>ans)  ans=c.size();
             }
        }
        return ans;
    }
};