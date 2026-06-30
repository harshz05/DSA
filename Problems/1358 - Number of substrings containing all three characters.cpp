/*
=========================================
LeetCode 1358 - Number of substrings containing all three characters
=========================================

Difficulty :medium

Pattern    :sliding window 

Time        :

Space       :

Date Solved : 2026-06-30

=========================================
*/
class Solution {
public:
    int numberOfSubstrings(string s) {

       int n = s.size() ;
       vector<int>freq ( 3,0 ) ;
       int left = 0 ;
       int ans = 0 ;

       for ( int i = 0 ; i< n ; i++) {
        freq[s[i] - 'a' ] ++ ;
        while ( freq[0] > 0 && freq[1] > 0 && freq[2] > 0 ) {
            ans += ( n - i   ) ;
            freq[s[left] - 'a'] -- ;
            left ++ ; 
        }

       }
       return ans ;
      
        
    }
};