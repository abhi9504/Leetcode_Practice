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



     int solveByTab(int i, int buy, vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                int profit = 0;

                if(buy) {
                    int buyKaro = -prices[i] + dp[i+1][0];
                    int skipKaro = 0 + dp[i+1][1];
                    profit = max(buyKaro, skipKaro);
                }
                else {
                    int sellKaro = prices[i] + dp[i+1][1] - fee;
                    int skipKaro = 0 + dp[i+1][0];
                    profit = max(sellKaro, skipKaro);
                }
                 dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }



    int solveBySpaceOptimization(int i, int buy, vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, 0));
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                int profit = 0;

                if(buy) {
                    int buyKaro = -prices[i] + next[0];
                    int skipKaro = 0 + next[1];
                    profit = max(buyKaro, skipKaro);
                }
                else {
                    int sellKaro = prices[i] + next[1] - fee;
                    int skipKaro = 0 + next[0];
                    profit = max(sellKaro, skipKaro);
                }
                 curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }




    int maxProfit(vector<int>& prices, int fee) {
      // Abhi Code Karo
      //   //1. function call by recursion TLE
     //   return solveByRec(0, 1, prices, fee);
    
    
    // // 2. function call using rec + 2D Dp memoization
    // int n = prices.size();
    // vector<vector<int>> dp(n, vector<int>(2, -1));
    // return solveByMemo(0, 1, prices, fee, dp);

    
    // // 3. function call using Tabulation
    // return solveByTab(0, 1, prices, fee);


    // 4. function call using Space Optimization
    return solveBySpaceOptimization(0, 1, prices, fee);

    }
};