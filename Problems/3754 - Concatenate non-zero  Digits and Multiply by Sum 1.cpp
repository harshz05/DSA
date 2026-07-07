/*
=========================================
LeetCode 3754 - Concatenate non-zero  Digits and Multiply by Sum 1
=========================================

Difficulty :easy 

Pattern    :

Time        :

Space       :

Date Solved : 2026-07-07

=========================================
*/
class Solution {
public:

int sum ( int num ){
    int s = 0 ;
    while ( num > 0) {
        s += num%10 ;
        num/=10 ;

    }
    return s ;
}
    long long sumAndMultiply(int n) {
        string s ;
        int m = n ;

        while (n>0) {
            int y = n%10 ;
            if ( y != 0) s.push_back( y+'0') ;
            n/=10 ;
        }
        reverse(s.begin(),s.end()) ;

        if ( s.empty()) return 0 ;
        else return 1LL * stoll(s)*sum(m) ; 

    }
};