class Solution {
public:
    void reverseString(vector<char>& s) {
        // Abhi Code Karo
        int n = s.size();
        vector<int> ans;

        for(int i=n-1; i>=0; i--) {
            ans.push_back(s[i]);
        }
        int idx = 0;
        for(int i=0; i<ans.size(); i++) {
            s[idx] = ans[i];
            idx++;
        } 
    }
};