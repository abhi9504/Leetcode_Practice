class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Abhi Code Karo
        // 2.Method: sort algo + 2ptr + BS concept
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i-1])  continue;
            for(int j=i+1; j<n; j++) {
                if(j > i+1 && nums[j] == nums[j-1])  continue;

                long long newTag = (long long) target - nums[i] - nums[j];
                int left = j+1;
                int right = n-1;
                while(left < right) {
                    if(nums[left] + nums[right] < newTag) left++;
                    else if(nums[left] + nums[right] > newTag) right--;
                    else {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        while(left < right && nums[left] == nums[left-1])  left++;
                        while(left < right && nums[right] == nums[right+1])  right--;
                    }
                }
            }
        }
        return ans;
    }
};

// TC=> O(N^3) + O(NlogN)
// SC=> O(N)