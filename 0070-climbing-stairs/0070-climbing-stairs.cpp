class Solution {
public:
    int solve(int n, vector<int>& dp) {
        // Base Case
        if(n == 1 || n == 2) return n;

        // step 2 check already exist condtion
        if(dp[n] != -1)  return dp[n];

        // step 3 return karane se phle usee dp mai store karao
        return dp[n] = solve(n-1, dp) +  solve(n-2, dp);
    }
    int climbStairs(int n) {
        // Abhi Code Karo
        // step1 create dp array n+1 size & initialize with -1;
        vector<int> dp(n+1, -1);

       return solve(n, dp);
    }
};