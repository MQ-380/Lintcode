/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

/*
一开始并没有想到用二分查找。。看了tag才反应过来。。这个思想还是要加强啊
二分查找一开始想到另外开一个函数做递归。。commit以后好像递归不行，会超过次数限制。。具体原因不明= =
所以看了参考以后才发现可以迭代。。。first，end不断在while修改就ok。。
还有一个问题就是在二分查找的条件判断的时候要用到first+1<end；而不是first！=end。。或许是因为会最后只有这两个存在，而错误的是end
如果这时候用后一个判断会导致死循环把。。
还有一个就是（first+end）/2和（end-first）/2+first的问题，后面那个可以解决在计算过程中超过int范围的问题！！！
尽量使用后面那个！！！
*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int first = 1;
        int end = n;
        while(first+1<end){
            int mid = (end-first)/2+first;
            if(isBadVersion(mid)) end = mid;
            else first = mid;
        }
        if(isBadVersion(first)) return first;
        else return end;
    }
};
