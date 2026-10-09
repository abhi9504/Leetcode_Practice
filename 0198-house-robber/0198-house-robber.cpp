class Solution {
public:
    int solveUsingRec(int i, vector<int>& nums) {
        // Base Case
        if(i >= nums.size())  return 0;

        // Two option choriKaro or NotChori
        int chori = nums[i] + solveUsingRec(i+2, nums);
        int notChori = 0 + solveUsingRec(i+1, nums);

        return max(chori, notChori);
    }


     int solveUsingMemo(int i, vector<int>& nums, vector<int>& dp) {
        // Base Case
        if(i >= nums.size())  return 0;

        // check already condition
        if(dp[i] != -1)  return dp[i];

        // Two option choriKaro or NotChori
        int chori = nums[i] + solveUsingMemo(i+2, nums, dp);
        int notChori = 0 + solveUsingMemo(i+1, nums, dp);

        return dp[i] = max(chori, notChori);
    }

    int rob(vector<int>& nums) {
        // Abhi Code Karo
        // //1. Recursion TLE 55/70 testcases passed only
        // return solveUsingRec(0, nums);

        // Method2: Recursion + memoization + 1D dp
        // Pass All TestCases and Submit
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solveUsingMemo(0, nums, dp);

    }
};


