/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000

**/

class Solution {
public:
    int countSubsetSum (vector <int> &arr, int n, int sum)
    {
        int t[n + 1][sum + 1];
        
        for (int i = 0; i <= n; i++)
        {
            t[i][0] = 1;
        }
        
        for (int j = 1; j <= sum; j++)
        {
            t[0][j] = 0;
        }
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                    t[i][j] = t[i - 1][j] + t[i - 1][j - arr[i - 1]];
                else
                    t[i][j] = t[i - 1][j];
            }
        }
        
        return t[n][sum];
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        int sum = 0;
        
        for (int i = 0; i < n; i++)
        {
            sum = sum + nums[i];
        }
        
        int s = (sum - target);
        
        if (s % 2 != 0)
            return 0;
        
        if (s < 0)
            return 0;
        
        s = s / 2;
        
        if (n == 1 && target != nums[0] && target != (-1 * nums[0]))
            return 0;
        
        return countSubsetSum(nums, n, s);
        
    }
};
