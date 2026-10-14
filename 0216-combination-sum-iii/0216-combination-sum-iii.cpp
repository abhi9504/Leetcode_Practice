class Solution {
public:
    void solve(vector<int>& candidates, int target, int i, vector<vector<int>>& ans, vector<int>& output, int cnt, int k) {
        // Base Case
        if(cnt > k)  return;
        if(cnt == k && target == 0) {
            ans.push_back(output);
            return;
        }
        if(target < 0) return;
        if(i >= candidates.size())  return;

        // 1 case ham solve karenge baaki recursion shambhal lega
        output.push_back(candidates[i]);
        // Include or exclude
        solve(candidates, target-candidates[i], i+1, ans, output, cnt+1, k);

        // BackTrack
        output.pop_back();

        // // check for duplicate combination
        // while(i+1 > candidates.size() && candidates[i] == candidates[i+1])  i++;

        // exclude
        solve(candidates, target, i+1, ans, output, cnt, k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        // abhi Code Karo
        vector<int> candidates = {1,2,3,4,5,6,7,8,9};
        int target = n;
        int cnt = 0;
        vector<vector<int>> ans;
        vector<int> output;
        int i = 0;

        solve(candidates, target, i, ans, output, cnt, k);

        return ans;
    }
};