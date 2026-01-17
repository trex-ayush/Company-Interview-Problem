class Solution {
  public:
    bool checkRedundancy(string &s) {
        stack<char> st;
        
        for (char ch : s) {
            if (ch == ')') {
                bool isRedundant = true;
                
                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }
                
                if (!st.empty()) st.pop(); 
                
                if (isRedundant) return true;
            } else {
                st.push(ch);
            }
        }
        
        return false;
    }
};
