/*
=========================================
LeetCode 172 - Factorial Trailing Zeroes
=========================================

Difficulty :easy

Pattern    :maths 

Time        :

Space       :

Date Solved : 2026-07-10

=========================================
*/
class Solution {
public:


    int trailingZeroes(int n) {
        int ans = 0 ;
        while ( n>0) {
            n/=5 ;
            ans = ans + n ;
        }
        return ans ;
    }
};