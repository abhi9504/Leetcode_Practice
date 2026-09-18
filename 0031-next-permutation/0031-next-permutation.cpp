class Solution {
public:
    void rev(vector<int>& nums, int s, int e) {
        while(s <= e) {
            swap(nums[s], nums[e]);
            s++;
            e--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        // Abhi Code Karo
        int n = nums.size();
        int i = n-2;

        while(i >= 0 && nums[i] >= nums[i+1]) {
            i--;
        }

        if(i >= 0) {
            int j = n-1;

            while(nums[j] <= nums[i]) {
                j--;
            }

            swap(nums[i], nums[j]);
        }

        rev(nums, i+1, n-1);
    }
};