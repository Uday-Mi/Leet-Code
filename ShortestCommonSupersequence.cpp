/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.
**/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int m = str1.size();
        int n = str2.size();
        
        int t[m + 1][n + 1];
        
        for (int i = 0; i <= m; i++)
        {
            t[i][0] = 0;
        }
        
        for (int j = 0; j <= n; j++)
        {
            t[0][j] = 0;
        }
        
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    t[i][j] = t[i - 1][j - 1] + 1;
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
        
        int i = m;
        int j = n;
        
        string str = "";
        
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                str = str1[i - 1] + str;
                i--;
                j--;
            }
            else
            {
                if (t[i - 1][j] > t[i][j - 1])
                {
                    str = str1[i - 1] + str;
                    i--;
                }
                else
                {
                    str = str2[j - 1] + str;
                    j--;
                }
            }
        }
        
        while (i > 0)
        {
            str = str1[i - 1] + str;
            i--;
        }
        
        while (j > 0)
        {
            str = str2[j - 1] + str;
            j--;
        }
        
        return str;
        
    }
};
