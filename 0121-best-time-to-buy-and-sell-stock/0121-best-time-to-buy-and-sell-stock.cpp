class Solution {
public:
    int maxProfit(vector<int>& prices) {
       // Q1. Day 5/30
       int n = prices.size();
       int maxProfit = 0;
       int minPrice = prices[0];
       for(int i=1; i<n; i++) {
        int curr = prices[i] - minPrice;
        maxProfit = max(maxProfit, curr);
        minPrice = min(minPrice, prices[i]);
       } 
       return maxProfit;
    }
};