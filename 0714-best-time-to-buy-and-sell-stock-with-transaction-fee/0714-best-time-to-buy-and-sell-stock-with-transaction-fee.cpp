class Solution {
public:
    int solveByRec(int i, int buy, vector<int>& prices, int fee) {
        // Base Case
        if(i == prices.size()) return 0;

        int profit = 0;
        if(buy) {
            int buyKaro = -prices[i] + solveByRec(i+1, 0, prices, fee);
            int skipKaro = 0+ solveByRec(i+1, 1, prices, fee);
            profit = max(buyKaro, skipKaro);
        }
        else {
            int sellKaro = prices[i] + solveByRec(i+1, 1, prices, fee) - fee;
            int skipKaro = 0 + solveByRec(i+1, 0, prices, fee);
            profit = max(sellKaro, skipKaro);
        }
        return profit;
    }



     int solveByMemo(int i, int buy, vector<int>& prices, int fee, vector<vector<int>>& dp) {
        // Base Case
        if(i == prices.size()) return 0;

        // check already exist condition
        if(dp[i][buy] != -1)  return dp[i][buy];

        int profit = 0;
        if(buy) {
            int buyKaro = -prices[i] + solveByMemo(i+1, 0, prices, fee, dp);
            int skipKaro = 0+ solveByMemo(i+1, 1, prices, fee, dp);
            profit = max(buyKaro, skipKaro);
        }
        else {
            int sellKaro = prices[i] + solveByMemo(i+1, 1, prices, fee, dp) - fee;
            int skipKaro = 0 + solveByMemo(i+1, 0, prices, fee, dp);
            profit = max(sellKaro, skipKaro);
        }
        return dp[i][buy] = profit;
    }


    int maxProfit(vector<int>& prices, int fee) {
      // Abhi Code Karo
      //   //1. function call by recursion TLE
     //   return solveByRec(0, 1, prices, fee);
    
    
    // 2. function call using rec + 2D Dp memoization
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solveByMemo(0, 1, prices, fee, dp);

    }
};