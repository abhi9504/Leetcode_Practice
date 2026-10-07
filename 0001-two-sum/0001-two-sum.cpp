class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Abhi Code Karo
        // Method3: Using hash map in single pass TC=> O(N), SC=> O(1)
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            int numToFind = target - nums[i];
            if(mp.find(numToFind) != mp.end()) {
                return {i, mp[numToFind]};
            }
            // agar mp mai nhi mila to curr element ki new entry map mai bna do
            mp[nums[i]] = i;
        }
        return {};
    }
};