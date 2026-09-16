class Solution {
public:
    void solve(int st, int e, vector<char>& s) {
         // Base Case
         if(st >= e) return;

          swap(s[st], s[e]);
          solve(st+=1, e-=1, s);

    }
    void reverseString(vector<char>& s) {
        // Abhi Code karo
        // Using Recursion
        int n = s.size();
    
        solve(0, n-1, s);
    }
};