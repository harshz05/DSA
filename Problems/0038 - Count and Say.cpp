/*
=========================================
LeetCode 38 - Count and Say
=========================================

Difficulty :medium

Pattern    :recursion 

Time        :

Space       :

Date Solved : 2026-06-28

=========================================
*/

class Solution {
public:
    string rle(string s) {
        if (s.empty()) return "";
        string ans;
        int cnt = 1;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                cnt++;
            } 
            else {
                ans += to_string(cnt);
                ans += s[i - 1];
                cnt = 1;
            }
        }
        ans += to_string(cnt);
        ans += s.back();
        return ans;
    }
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string prev = countAndSay(n - 1);
        return rle(prev);
    }
};
