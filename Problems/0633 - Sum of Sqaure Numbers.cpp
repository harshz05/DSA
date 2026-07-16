/*
=========================================
LeetCode 633 - Sum of Sqaure Numbers
=========================================

Difficulty :Easy

Pattern    :two pointers (converging) 

Time        :

Space       :

Date Solved : 2026-07-16

=========================================
*/
class Solution {
public:
    bool judgeSquareSum(int c) {
        
        long long st = 0 ;
        long long end = sqrt(c) ;

        while(st<=end) {
            long long s = st*st + end * end ;
            if ( s == c) return true ;
            if (s<c) st ++ ;
            else end-- ;
        }
        return false ;

        
    }
};