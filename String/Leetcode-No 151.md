#No.151 Reverse Words in String

##最初想法

最初思路就是利用July的书中所写道的三步走方法，先转单词再转整个字符串，例如：

源字符串为『abc def ghi』，

第一步先分割单词，与此同时进行一个个翻转，最后得到的字符串是"cba fed ihg";

第二步在整体翻转字符串有："ghi def abc"

两步完成了翻转。

注：*其实两步先后顺序颠倒并不会影响这里的答案*



##问题处理

但这里的问题中有一些细节问题需要处理，问题和个人解决方案分别如下(也就是题目中Clarification所提到的)：

1）**开头的所有空格需要去除**

​      因为有一个bool变量的标示，所以出现前驱的空格时候，k字符串仍然为空，所以第一个空格出现不会改变答案，并且此时bool变量置为true，后续的空格会被跳过，而且这里两个单词的加空格的工作实在读到空格之后的第一个字符时做的，此时判断rs辅助字符串是否为空，若为空则可判定的是前面均为前空格，并没有字母出现过，那就跳过。反之则需要增加一个空格。

2）**两个单词中间有多个空格**

​     处理方法基本同上。用一个bool变量进行标记，如果出现空格就标记为true，那么后续再处理连续的空格时可以直接跳过。遇到第一个空格的时候就进行之前字符串的翻转以及加上到答案字符串上(这里的两个均为自己声明的辅助字符串)，

3）**最后一个单词到结尾之间没有空格**

​      直接判断出循环之后最后一个字符是否为blank，若不是，那么直接将k翻转加到rs上，若是则不用做任何操作。

##最终解法

(C++)：

```
class Solution {
public:
void reverseWords(string &s) {
	int last = 0;
    reverse(s.begin(),s.end());//先全部reverse让所有前驱空格置于最后
    string rs,k;
    int t = 0;
    bool blank = false;
    for(int j=0;j<s.size();j++){
       if(s[j]!=' '){
           if(blank && !rs.empty()) rs+=" ";
           k+=s[j];
           blank = false;
        }else{
            if(!blank) {
                reverse(k.begin(),k.end());
                rs+=k;
                k="";
            }
            blank = true;
          }
    }
    if(k!=" " && !blank){reverse(k.begin(),k.end());rs+=k;}   //处理最后没有空格情形
    s = rs;
  }
};
```

