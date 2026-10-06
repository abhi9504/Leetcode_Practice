class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Abhi Code Karo
        // 1. Method Using Map
        int n = nums.size();
        vector<int> ans;
        int candi1 = 0, cnt1 = 0;
        int candi2 = 0, cnt2 = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == candi1) cnt1++;
            else if(nums[i] == candi2)  cnt2++;
            else if(cnt1 == 0) {
                candi1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0) {
                candi2 = nums[i];
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        // yaha tk candi1 and cand2 ban chuka hoga
        // check if freq of those candidate is > n/3
         cnt1 = 0;
         cnt2 = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == candi1)  cnt1++;
            else if(nums[i] == candi2)  cnt2++;
        }
        if(cnt1 > n/3) {
            ans.push_back(candi1);
        }
        if(cnt2 > n/3) ans.push_back(candi2);

        return ans;
    }
};