class Solution {
public:
    int solve(int i, int buy, int limit, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        int n = prices.size();
        // Base Case
        if(i == n)  return 0;
        if(limit == 0)  return 0;

        // check already exist condition
        if(dp[i][buy][limit] != -1)  return dp[i][buy][limit];

        int profit = 0;
        if(buy) {
            int buyKaro = -prices[i] + solve(i+1, 0, limit, prices, dp);
            int skipKaro = 0 + solve(i+1, 1, limit, prices, dp);
            profit = max(buyKaro, skipKaro);
        }
        else {
            int sellKaro = prices[i] + solve(i+1, 1, limit-1, prices, dp);
            int skipKaro = 0 + solve(i+1, 0, limit, prices, dp);
            profit = max(sellKaro, skipKaro);
        }
        return dp[i][buy][limit] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // Abhi Code Karo
        // Here is 3d dp use rec + 3d Dp
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return solve(0, 1, 2, prices, dp);
    }
};