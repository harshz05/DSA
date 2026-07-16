/*
=========================================
LeetCode 3867 - Sum og GCD of formed Pairs
=========================================

Difficulty :medium

Pattern    :two pointers,sorting ,number theory 

Time        :

Space       :

Date Solved : 2026-07-16

=========================================
*/
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>faltu(n) ;
        int mx=0 ;
        for ( int i = 0 ; i < n ; i++) {
            mx=max(mx,nums[i]) ;
            faltu[i] = gcd(nums[i],mx) ;
        }
        sort(faltu.begin() , faltu.end()) ;
        long long ans = 0 ;
        int l = 0 ;
        int r = n-1 ;

        while ( l<r) {
            ans+=gcd(faltu[l],faltu[r]) ;
            l++ ;
            r-- ;
        }
        return ans ;
    } 
};