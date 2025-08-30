class Solution {
  public:
    int maxDepth(string s) {
        stack<char> st;
        int maxLen = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }else if(s[i] == ')'){
                maxLen = max(maxLen, (int)st.size());
                st.pop();
            }
        }
        return maxLen;
    }
};