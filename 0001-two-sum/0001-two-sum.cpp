class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Abhi Code Karo
        // Method1: Brute Force TC=> O(N2) SC=> O(1)
        int n = nums.size();
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};