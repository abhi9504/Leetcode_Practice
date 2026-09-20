class Solution {
public:
    void reverseString(vector<char>& s) {
       int n = s.size();
       vector<char> ans;
       for(int i=n-1; i>=0; i--){
         ans.push_back(s[i]);
       } 
       int i =0;
       while(i < ans.size()) {
        s[i] = ans[i];
        i++;
       }
    }
};