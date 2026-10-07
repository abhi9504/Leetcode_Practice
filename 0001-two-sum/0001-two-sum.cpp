class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Abhi Code Karo
        // Method2: Using hash map TC=> O(N) + O(N), SC=> O(1)
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[nums[i]] = i;
        }
        for(int i=0; i<n; i++) {
            int numToFind = target - nums[i];
            if(mp.find(numToFind) != mp.end() && mp[numToFind] != i) {
                return {i, mp[numToFind]};
            }
        }
        return {};
    }
};