class Solution {
public:
    int dp[101];
    int solve(int i, int n, vector<int>& nums) {
        // Base Case
        if(i >= n) return 0;

        // check already exist cond
        if(dp[i]  != -1)  return dp[i];

        int chori = nums[i] + solve(i+2, n, nums);
        int Notchori = 0 + solve(i+1, n, nums);

        return dp[i] = max(chori, Notchori);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();

        // edge case hamesha yaad akro bhul jate h
        if(n == 1)  return nums[0];

        // 1 to n
        memset(dp, -1, sizeof(dp));
        int case1 = solve(1, n, nums);
        // 0 to n-1
        memset(dp, -1, sizeof(dp));
        int case2 = solve(0, n-1, nums);

        return max(case1, case2);
    }
};