/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
**/

class Solution {
    public boolean isValid(String s) {
        
        Stack <Character> stk = new Stack <> ();
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            char ch = s.charAt(i);
            if (open(ch))
            {
                stk.push(ch);
            }
            else if (close(ch))
            {
                if (stk.empty())
                    return false;
                char c = stk.peek();
                char c1 = pair(ch);
                if (c1 == c)
                    stk.pop();
                else
                    return false;
            }
            else
                return false;
        }
        if (stk.empty())
            return true;
        return false;
        
    }
    
    boolean open (char ch)
    {
        if (ch == '{' || ch == '[' || ch == '(')
            return true;
        return false;
    }
    
    boolean close (char ch)
    {
        if (ch == '}' || ch == ']' || ch == ')')
            return true;
        return false;
    }
    
    char pair (char ch)
    {
        if (ch == ')')
            return '(';
        if (ch == ']')
            return '[';
        if (ch == '}')
            return '{';
        return 'f';
    }
}
