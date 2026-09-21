class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // abhi Code Karo
        int n = nums.size();
        map<int, int> mp;
        for(int i=0; i<n; i++) {
         mp[nums[i] * nums[i]]++;
        }
        int i = 0;
        for(auto it : mp) {
            while(it.second--){
            nums[i] = it.first;
            i++;
            }
        }

        return nums;
    }
};