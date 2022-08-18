/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
**/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        string str = s;
        reverse(s.begin(), s.end());
        
        int n = s.size();
        
        int t[n + 1][n + 1];
        
        for (int i = 0; i <= n; i++)
        {
            t[i][0] = 0;
            t[0][i] = 0;
        }
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str[i - 1] == s[j - 1])
                    t[i][j] = t[i - 1][j - 1] + 1;
                else
                    t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }
        
        return t[n][n];
        
    }
};
