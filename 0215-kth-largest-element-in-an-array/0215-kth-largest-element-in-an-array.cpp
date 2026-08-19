class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       // Q2. Day-3/30
       int n = nums.size();
       sort(nums.begin(), nums.end());
       return nums[n-k]; 
    }
};