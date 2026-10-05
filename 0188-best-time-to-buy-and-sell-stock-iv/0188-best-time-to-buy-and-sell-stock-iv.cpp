class Solution {
public:
    int solveByRec(int i, int buy, int k, vector<int>& prices) {
        // Base Case
        if(i == prices.size())  return 0;
        if(k == 0) return 0;

        int profit = 0;
        if(buy) {
            int buyKaro = -prices[i] + solveByRec(i+1, 0, k, prices);
            int skipKaro = 0 + solveByRec(i+1, 1, k, prices);
            profit = max(buyKaro, skipKaro);
        }
        else {
            int sellKaro = prices[i] + solveByRec(i+1, 1, k-1, prices);
            int skipKaro = 0 + solveByRec(i+1, 0, k, prices);
            profit = max(sellKaro, skipKaro);
        }
        return profit;
    }


     int solveByMemo(int i, int buy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        // Base Case
        if(i == prices.size())  return 0;
        if(k == 0) return 0;

        // check already exist condition
        if(dp[i][buy][k] != -1) return dp[i][buy][k];

        int profit = 0;
        if(buy) {
            int buyKaro = -prices[i] + solveByMemo(i+1, 0, k, prices, dp);
            int skipKaro = 0 + solveByMemo(i+1, 1, k, prices, dp);
            profit = max(buyKaro, skipKaro);
        }
        else {
            int sellKaro = prices[i] + solveByMemo(i+1, 1, k-1, prices, dp);
            int skipKaro = 0 + solveByMemo(i+1, 0, k, prices, dp);
            profit = max(sellKaro, skipKaro);
        }
        return dp[i][buy][k] = profit;
    }


     int solveByTab(int i, int buy, int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                for(int it=1; it<=k; it++) {

                     int profit = 0;
                        if(buy) {
                            int buyKaro = -prices[i] + dp[i+1][0][it];
                            int skipKaro = 0 + dp[i+1][1][it]; 
                            profit = max(buyKaro, skipKaro);
                        }
                        else {
                            int sellKaro = prices[i] + dp[i+1][1][it-1];
                            int skipKaro = 0 + dp[i+1][0][it]; 
                            profit = max(sellKaro, skipKaro);
                        }
                       dp[i][buy][it] = profit;
                }
            }
        }
       return dp[0][1][k];
    }


     int solveBySpaceOptimization(int i, int buy, int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        vector<vector<int>> next(2, vector<int>(k+1, 0));

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                for(int it=1; it<=k; it++) {

                     int profit = 0;
                        if(buy) {
                            int buyKaro = -prices[i] + next[0][it];
                            int skipKaro = 0 + next[1][it]; 
                            profit = max(buyKaro, skipKaro);
                        }
                        else {
                            int sellKaro = prices[i] + next[1][it-1];
                            int skipKaro = 0 + next[0][it]; 
                            profit = max(sellKaro, skipKaro);
                        }
                       curr[buy][it] = profit;
                }
                next = curr;
            }
        }
       return curr[1][k];
    }




    int maxProfit(int k, vector<int>& prices) {
        // Abhi Code Karo
        // // 1. function call by using Recursion TLE aayega
        // return solveByRec(0, 1, k, prices);


        // // 2. function call for Rec + memo using 3D dp
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        // return solveByMemo(0, 1, k, prices, dp);


        // // 3. function call using Tabulationa
        // return solveByTab(0, 1, k, prices);

        // 4. function call by space Optimization
        return solveBySpaceOptimization(0, 1, k, prices);
    }
};