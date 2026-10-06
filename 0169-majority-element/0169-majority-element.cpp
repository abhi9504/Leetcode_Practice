class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Abhi Code Karo
        // 3.Method: Using Moore Voting Algo
        int n = nums.size();
        int candi = nums[0];
        int cnt = 1;
        for(int i=1; i<n; i++) {
            if(nums[i] == candi) cnt++;
            else if(cnt == 0) {
                candi = nums[i];
                cnt = 1;
            }
            else cnt--;
        }
       return candi;
    }
};  