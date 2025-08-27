class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string res = "";
        stack<char> st;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                if(!st.empty()) res += s[i];
                st.push(s[i]);
            }else{
                st.pop();
                if(!st.empty()) res += s[i];
            }
        }
        return res;
    }
};