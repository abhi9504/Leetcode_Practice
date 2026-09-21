class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // Abhi Code karo
        if(k <= 1)  return 0;
        int n = nums.size();
        int cnt = 0;
        long long prod = 1;
        int i = 0;
        for(int j=0; j<n; j++) {
            prod *= nums[j];

            while(prod >= k) {
                prod /= nums[i];
                i++;
            }
           cnt += (j-i+1);
        }
        return cnt;
    }
};