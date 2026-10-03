class Solution {
public: 
    int solve(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        // Base Case
        if(i == prices.size())  return 0;

        // check already exist condition
        if(dp[i][buy] != -1)  return dp[i][buy];

        int profit = 0;
        if(buy) {
            int buyKaro = -prices[i] + solve(i+1, 0, prices, dp);
            int skipKaro = 0 + solve(i+1, 1, prices, dp);
            profit = max(buyKaro, skipKaro);
        }
        else {
            // sell Karo
            int sellKaro = prices[i] + solve(i+1, 1, prices, dp);
            int skipKaro = 0 + solve(i+1, 0, prices, dp);
            profit = max(sellKaro, skipKaro);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
      // Abhi Code Karo
      int n = prices.size();
      vector<vector<int>> dp(n, vector<int>(2, -1));
      return solve(0,1,prices, dp);  
    }
};