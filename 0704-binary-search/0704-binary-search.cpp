class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Q1 Day 4/30
        int n = nums.size();
        int s = 0;
        int e = n-1;
        while(s <= e) {
            int mid = (s+e)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) s = mid + 1;
            else e = mid - 1;
        }
        return -1;
    }
};