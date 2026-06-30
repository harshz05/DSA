/*
=========================================
LeetCode 2063 - Vowels of All Substrings
=========================================

Difficulty :medium 

Pattern    :

Time        :

Space       :

Date Solved : 2026-06-30

=========================================
*/
class Solution {
public:
    long long countVowels(string word) {

        int n = word.size() ;
        long long ans = 0;

        for ( int i = 0 ; i < n ; i++) {
            char ch  = word[i] ;

            if ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
             ans += 1LL * (i+1) * (n-i) ;
            }
        }


        
 return ans ;

    }
};