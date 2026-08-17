class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Abhi Code Karo
        int n = nums.size();
        vector<pair<int, int>> p;
        for(int i=0; i<n; i++) {
            p.push_back({nums[i], i});
        }
        // Sort
        sort(p.begin(), p.end());
        // Use Two ptr
        int s = 0;
        int e = p.size()-1;
        while(s < e) {
            int sum = p[s].first + p[e].first;
            if(sum == target)  return {p[s].second, p[e].second};
            else if(sum > target) e--;
            else s++;
        }
         return {};
    }
};