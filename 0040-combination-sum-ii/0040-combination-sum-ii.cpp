class Solution {
public:
    void solve(vector<int>& candidates, int target, int i, vector<vector<int>>& ans, vector<int>& output) {
        // Base Case
        if(target == 0) {
            ans.push_back(output);
            return;
        }
        if(target < 0)  return;
        if(i >= candidates.size())  return;

        // 1 case ham solve karenge baaki recursion shambhal lega
        output.push_back(candidates[i]);
        // include or exclude
        solve(candidates, target-candidates[i], i+1, ans, output);

        // BackTrack
        output.pop_back();

        // for skip duplicate combination
        while(i+1 < candidates.size() && candidates[i] == candidates[i+1]) {
            i++;
        }

        // exclude
        solve(candidates, target, i+1, ans, output);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Abhi Code Karo
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> output;
        int i = 0;
        solve(candidates, target, i, ans, output);

        return ans;
    }
};