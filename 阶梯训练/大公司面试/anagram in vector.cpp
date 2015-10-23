/*
给出一个字符串数组S，找到其中所有的乱序字符串(Anagram)。如果一个字符串是乱序字符串，那么他存在一个字母集合相同，但顺序不同的字符串也在S中。
样例
对于字符串数组 ["lint","intl","inlt","code"]
返回 ["lint","inlt","intl"]
注意
所有的字符串都只包含小写字母
*/

//1 注意不能够直接破坏strs，因为输出要原来的内容
//2 利用排序后的字符相同，就在处理的时候用map来对应排序后的字符串和对应次数之间的关系。
//3 输出的时候先进行排序，然后根据这个内容去map中寻找内容，如果大于1就输出。

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        map<string,int>a;
        for(int j=0;j<strs.size();j++){
            string s = strs[j];
            sort(s.begin(),s.end());
            a[s]++;
        }
        vector<string> anagrams;
        for(int j=0;j<strs.size();j++){
           auto tmp = strs[j];
           sort(tmp.begin(),tmp.end());
           if(a[tmp]>1){
               anagrams.push_back(strs[j]);
           }
        }
        return anagrams;
    }
};
