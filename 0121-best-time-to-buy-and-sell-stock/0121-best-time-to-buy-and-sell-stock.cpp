class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Abhi Code Karo
        int n = prices.size();
        int maxi = 0;
        int mini = prices[0];

        for(int i=1; i<n; i++) {
            int profit = prices[i] - mini;
            maxi = max(maxi, profit);
            mini = min(mini, prices[i]);
        }
        return maxi;
    }
};