class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       // Abhi Code Karo
       int n = nums.size();
       int j = 0;
       for(int i=0; i<n; i++) {
         if(nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
         }
       }
    }
};