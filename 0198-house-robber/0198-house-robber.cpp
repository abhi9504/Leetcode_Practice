class Solution {
public:
    int dp[101];
    int solve(int i, vector<int>& nums) {
        // Base Case
        if(i >= nums.size())  return 0;

        // check already exist condition
        if(dp[i] != -1)  return dp[i];

        int chori = nums[i] + solve(i+2, nums);
        int Notchori = 0 + solve(i+1, nums);

        return dp[i] = max(chori, Notchori);
    }
    int rob(vector<int>& nums) {
     // Abhi Code Karo
     memset(dp, -1, sizeof(dp));
     return solve(0, nums);   
    }
};