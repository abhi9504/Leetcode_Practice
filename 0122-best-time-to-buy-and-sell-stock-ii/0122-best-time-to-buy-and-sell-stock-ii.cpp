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
    int solveTab(vector<int>& prices) {
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
               // sell Karo
               int sellKaro = prices[i] + dp[i+1][1];
               int skipKaro = 0 + dp[i+1][0];
               profit = max(sellKaro, skipKaro);
        } 
              dp[i][buy] = profit;
     }
  }
      return dp[0][1];
 }


    int solveSpace(vector<int>& prices) {
        int n = prices.size();
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
               // sell Karo
               int sellKaro = prices[i] + next[1];
               int skipKaro = 0 + next[0];
               profit = max(sellKaro, skipKaro);
        } 
              curr[buy] = profit;
     }
         next = curr;
   }
      return  next[1];
}

    int maxProfit(vector<int>& prices) {
      // Abhi Code Karo
      int n = prices.size();
    // function call using recursion + memoiazation
    //   vector<vector<int>> dp(n, vector<int>(2, -1));
    //   return solve(0,1,prices, dp);  

      // function call for Tabulation
    //   return solveTab(prices);

    // function call by space optimization
      return solveSpace(prices);
    }
};