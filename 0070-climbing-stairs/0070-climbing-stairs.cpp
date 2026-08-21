class Solution {
public:
    int solve(int n, vector<int>& dp) {
        // Base Case
        if(n == 1 || n == 2) return n;

        // check already exist condition
        if(dp[n] != -1)  return dp[n];

        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }
    int climbStairs(int n) {
        // Q2. Day 5/30
        vector<int> dp(n+1, -1);

        return solve(n, dp);
    }
};