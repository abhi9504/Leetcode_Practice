class Solution {
public:
    int solveTab(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0;
        int prev1 = nums[0];

        for(int i=1; i<n; i++) {
            int chori = prev2 + nums[i];
            int Notchori = prev1 + 0;
            int ans = max(chori, Notchori);
            // aage badhao
            prev2 = prev1;
            prev1 = ans;
        }
       return prev1;
    }
    int rob(vector<int>& nums) {
        // Abhi Code Karo
        return solveTab(nums);
    }
};