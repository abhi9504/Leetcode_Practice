class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // Abhi Code Karo
        // solve using 3 ptr
        int n = nums.size();
        vector<int> ans(n);
        int s = 0;
        int e = n-1;
        int idx = n-1;

        while(s <= e) {
            int sSquare = nums[s] * nums[s];
            int eSquare = nums[e] * nums[e];

            if(eSquare > sSquare) {
                ans[idx] = eSquare;
                e--;
            }
            else {
                ans[idx] = sSquare;
                s++;
            }
            idx--;
        }
        return ans;
    }
};