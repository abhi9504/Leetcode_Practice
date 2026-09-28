class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        // Base Case
        if(i >= nums.size())  return 0;

        // check already exist cond
        if(dp[i] != -1)  return dp[i];

        int Chori = nums[i] + solve(nums, i+2, dp);
        int NotChori = 0 + solve(nums, i+1, dp);

        return dp[i] = max(Chori, NotChori);
    }
    int rob(vector<int>& nums) {
      // Abhi Code Karo
      int n = nums.size();
      vector<int> dp(n+1, -1);
      int i = 0;

      return solve(nums, i, dp);  
    }
};