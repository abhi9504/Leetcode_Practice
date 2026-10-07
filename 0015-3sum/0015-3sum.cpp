class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Abhi Code Karo
        // Solve Using 3 ptr 
        int n = nums.size();
        // Step1: sort the array
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++) {
            // skip the same element
            if(i > 0 && nums[i] == nums[i-1])  continue;
            int j = i+1;
            int k = n-1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                // 3 case possible ho skta h
                //case1 sum == target ho to
                if(sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // check for same element for j & k
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--; 
                }
                else if(sum < 0) {
                    j++;
                }
                else {
                    k--;     // sum > 0 ho to
                }
            }
        }
        return ans;
    }
};