/*
=========================================
LeetCode 1291 - Sequential Digits
=========================================

Difficulty :easy 
 
Pattern    :

Time        :

Space       :

Date Solved : 2026-07-13

=========================================
*/
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans ;
        for ( int i = 2 ; i<= 9 ;i++) {
            for ( int start =1 ; start+i-1 <=9;start++) {
                int num = 0 ;

                for (int d= start  ;d<start +i ;d++ ) {
                    num = num*10  +d ; }
                
                if(num>= low && num<=high) ans.push_back(num) ;
                
            }
        }
        return ans ;
        
    }
};