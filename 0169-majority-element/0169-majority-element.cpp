class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Abhi Code Karo
        int n = nums.size();
        sort(nums.begin(), nums.end());

        return nums[n/2];
    }
};  