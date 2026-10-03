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

    int solveTab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                for(int limit=1; limit<=2; limit++) {
                      int profit = 0;

                        if(buy) {
                            int buyKaro = -prices[i] + dp[i+1][0][limit];
                            int skipKaro = 0 + dp[i+1][1][limit];
                            profit = max(buyKaro, skipKaro);
                        }
                        else {
                            int sellKaro = prices[i] + dp[i+1][1][limit-1];
                            int skipKaro = 0 + dp[i+1][0][limit];
                            profit = max(sellKaro, skipKaro);
                        }
                        dp[i][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }

    int solveSpace(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));

         for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                for(int limit=1; limit<=2; limit++) {
                      int profit = 0;

                        if(buy) {
                            int buyKaro = -prices[i] + next[0][limit];
                            int skipKaro = 0 + next[1][limit];
                            profit = max(buyKaro, skipKaro);
                        }
                        else {
                            int sellKaro = prices[i] + next[1][limit-1];
                            int skipKaro = 0 + next[0][limit];
                            profit = max(sellKaro, skipKaro);
                        }
                        curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }


    int maxProfit(vector<int>& prices) {
        // Abhi Code Karo
        // Here is 3d dp use rec + 3d Dp
        // 1. function call by recu + memoization
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        // return solve(0, 1, 2, prices, dp);


        // 2. function call by Tabulation
        // return solveTab(prices);

        
        // 3. function call by space optimization
       return solveSpace(prices);

    }
};