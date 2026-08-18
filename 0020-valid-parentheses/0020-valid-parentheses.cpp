class Solution {
public:
    bool isValid(string s) {
        // Q2  Day 2 / 30 
    int n = s.size();
    stack<char> st;
    for(int i=0; i<n; i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        else {
            if(!st.empty() && ((st.top() == '(' && s[i] == ')' ) || (st.top() == '{' && s[i] == '}') || (st.top() == '[' && s[i] == ']'))) {
                st.pop();
            }
            else return false;
        }
    }
     if(st.empty()) {
        return true;
     }
     else {
        return false;
     }
    }
};