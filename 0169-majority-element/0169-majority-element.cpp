class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Abhi Code Karo
        // 2.Method: Using Map
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
        }
        // Traverse on map
        for(auto it : mp) {
            if(it.second > n/2) {
                return it.first;
            }
        }
        return -1;
    }
};  