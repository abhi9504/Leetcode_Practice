class Solution {
public:
    void solve(vector<int>& candidates, int target, int i, vector<vector<int>>& ans, vector<int>& output) {
        // Base Case
        if(target == 0) {
            // target 0 ka mtlb, mere output wali list me ek answer bn chuka h,
            // then store this answer in ans wali vector
            ans.push_back(output);
            return;
        }

        if(target < 0) return;
        if(i >= candidates.size())  return;

        // 1 case hm solve karenge baaki recursion shambhal lega
        // Include or Exclude pattern
        output.push_back(candidates[i]);
        solve(candidates, target-candidates[i], i, ans, output);

        // BackTrack
        output.pop_back();

        // exclude
        solve(candidates, target, i+1, ans, output);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Abhi Code Karo
        vector<vector<int>> ans;
        vector<int> output;
        int i = 0;
        solve(candidates, target, i, ans, output);

        return ans;
    }
};