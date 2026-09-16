class Solution {
public:
    void solve(int i, vector<vector<int>>& ans, vector<int>& output, vector<int>& nums) {
        // Base Case
        if(i >= nums.size()) {
            ans.push_back(output);
            return;
        }

        // Include
        output.push_back(nums[i]);
        solve(i+1, ans, output, nums);

        // Exclude and backtrack
        output.pop_back();
        solve(i+1, ans, output, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // Abhi Code Karo
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> output;

        solve(0, ans, output, nums);

        return ans;
    }
};