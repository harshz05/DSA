/*
=========================================
LeetCode 3158 - Find the XOR of numbers Which appear twice
=========================================

Difficulty :easy 

Pattern    :bit manipulation

Time        :

Space       :

Date Solved : 2026-06-27

=========================================
*/

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {

        unordered_map < int , int > mp ;
        for ( int x : nums ) {
            mp[x] ++ ;
        }
        int ans = 0 ;
        for ( auto x : mp ) {
            if ( x.second == 2 ) ans = ans ^ x.first ; 
        }
        return ans ;
        
    }
};
