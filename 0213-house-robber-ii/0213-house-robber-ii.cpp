class Solution {
public:
    int dp[101];
    int solve(vector<int>& nums, int i, int n) {
        // base case
        if(i >= n)  return 0;

        // check dp condition
        if(dp[i] != -1)  return dp[i];

        // recursive case
        int pick = nums[i] + solve(nums, i+2, n);
        int nopick = solve(nums, i+1, n);

        return dp[i] = max(pick, nopick);
    }
    int rob(vector<int>& nums) {
        // Abhi code Karo
        int n = nums.size();
        // vector<int> dp(n, -1);
        memset(dp, -1, sizeof(dp));

        // edge case bhul jate hai
        if(n == 1)  return nums[0];

        memset(dp, -1, sizeof(dp));
        int case1 = solve(nums, 0, n-1);
        // fill(dp.begin(), dp.end(), -1);
        memset(dp, -1, sizeof(dp));
        int case2 = solve(nums, 1, n);

        return max(case1, case2);
    }
};