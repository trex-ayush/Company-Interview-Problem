class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char> st;
        int i = 0;

        while(i < n){
            if(!st.empty() && st.top() == s[i]) st.pop();
            else st.push(s[i]);
            i++;
        }
        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};