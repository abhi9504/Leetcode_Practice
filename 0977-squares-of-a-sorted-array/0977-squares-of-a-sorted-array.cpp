class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       // Abhi Code Karo
       int n = nums.size();
       vector<int> ans(n);
       int s = 0;
       int e = n-1;
       int idx = n-1;

       while(s <= e) {
        long long int sSq = nums[s] * nums[s];
        long long int eSq = nums[e] * nums[e];

        if(eSq > sSq) {
            ans[idx] = eSq;
            e--;
            idx--;
        }
        else {
            ans[idx] = sSq;
            s++;
            idx--;
        }
       } 
       return ans;
    }
};