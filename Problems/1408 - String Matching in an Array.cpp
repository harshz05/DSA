/*
=========================================
LeetCode 1408 - String Matching in an Array
=========================================

Difficulty :easy 

Pattern    :string matching ..kmp algo 

Time        :

Space       :

Date Solved : 2026-06-29

=========================================
*/
class Solution {
public:
    vector<int> buildLPS(string pattern){
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
    vector<string> stringMatching(vector<string>& words) {

        vector<string>ans ;

        for ( int i = 0 ; i  <words.size() ; i++) {
            for ( int j = 0; j < words.size() ;j++) {

                if ( i == j ) continue ;

                if (  KMP( words[j] , words[i])) {
                    ans.push_back( words[i]) ;
                    break ;
                }
            }
        }
        return ans ;





        return ans ;
    }
};