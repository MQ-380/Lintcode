/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.
*/

/*
要考虑一个数字的情况！
循环不用到底。。只要找到相同的就能break了

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1) return false;  
        for(int j=0;j<nums.size();j++){
            if(nums[j]==nums[j+1]) return true;
        }
        return false;
    }
};
