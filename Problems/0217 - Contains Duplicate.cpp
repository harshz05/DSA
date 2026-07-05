/*
=========================================
LeetCode 217 - Contains Duplicate
=========================================

Difficulty :easy

Pattern    :hash table 

Time        :

Space       :

Date Solved : 2026-07-05

=========================================
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        return unordered_set<int>(nums.begin(),nums.end()).size() != nums.size() ;

     
    }
};
