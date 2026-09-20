class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      // Abhi Code Karo
      int n = nums.size();
      int j = 1;
      for(int i=1; i<n; i++) {
        if(nums[i] != nums[j-1]) {
            nums[j] = nums[i];
            j++;
        }
      }  
      return j;
    }
};