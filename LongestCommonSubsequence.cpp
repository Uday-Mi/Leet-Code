/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
**/

class Solution {
public:
    
    int t[1001][1001];
    
    int LCS (string s1, string s2, int m, int n)
    {
        if (n == 0 || m == 0)
            return 0;
        
       if (t[m][n] != -1)
           return t[m][n];
        
        if (s1[m - 1] == s2[n - 1])
            return t[m][n] = LCS(s1, s2, m - 1, n - 1) + 1;
        else
            return t[m][n] = max(LCS(s1, s2, m, n - 1), LCS(s1, s2, m - 1, n));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        memset(t, -1, sizeof(t));
        
        int m = text1.size();
        int n = text2.size();
        
        return LCS(text1, text2, m, n);
        
    }
};
