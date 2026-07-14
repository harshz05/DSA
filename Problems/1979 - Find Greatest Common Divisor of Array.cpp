/*
=========================================
LeetCode 1979 - Find Greatest Common Divisor of Array
=========================================

Difficulty :easy 

Pattern    :

Time        :

Space       :

Date Solved : 2026-07-14

=========================================
*/
class Solution {
public:

int gcd(int a, int b) {
    while (b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
    int findGCD(vector<int>& nums) {
        int x = *min_element(nums.begin(),nums.end()) ;
        int y = *max_element(nums.begin(),nums.end()) ;

        return gcd(x,y) ;
    }
};