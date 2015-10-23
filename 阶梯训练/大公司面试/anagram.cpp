//写出一个函数 anagram(s, t) 去判断两个字符串是否是颠倒字母顺序构成的
//样例
//给出 s="abcd"，t="dcab"，返回 true


//因为如果符合条件则排序后的内容相同，即可判断。
//所用STL：sort():
class Solution {
public:
    //@param s: The first string
    //@param b: The second string
    //@return true or false
    bool anagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        sort(s.begin(),s.end()); 
        sort(t.begin(),t.end());
        if(s!=t) return false;
        return true;
     }
};
