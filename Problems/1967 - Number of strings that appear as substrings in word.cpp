/*
=========================================
LeetCode 1967 - Number of strings that appear as substrings in word
=========================================

Difficulty :easy 

Pattern    :strings ..kmp algorithm

Time        :O(n+m) 

Space       :

Date Solved : 2026-06-29

=========================================
*/

class Solution {
public:

    vector<int> buildLPS(string pattern)
    {
        int n = pattern.size();

        vector<int> lps(n);

        int len = 0;
        int i = 1;

        while (i < n)
        {
            if (pattern[i] == pattern[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    bool KMP(string text, string pattern)
    {
        vector<int> lps = buildLPS(pattern);

        int i = 0;
        int j = 0;

        while (i < text.size())
        {
            if (text[i] == pattern[j])
            {
                i++;
                j++;
            }

            if (j == pattern.size())
                return true;
            else if (i < text.size() && text[i] != pattern[j])
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return false;
    }
    int numOfStrings(vector<string>& patterns, string word)
    {
        int cnt = 0;
        for (string &pat : patterns)
        {
            if (KMP(word, pat))
                cnt++;
        }
        return cnt;
    }
};
