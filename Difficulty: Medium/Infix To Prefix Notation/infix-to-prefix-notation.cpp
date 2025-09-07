class Solution {
  public:
    int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }
    string infixToPrefix(string &s) {
        string result;
        stack<char> st;
        
        // Step 1: Reverse the string
        reverse(s.begin(), s.end());
        
        // Step 2: Swap '(' with ')' and vice versa
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') s[i] = ')';
            else if (s[i] == ')') s[i] = '(';
        }
        
        // Step 3: Convert to postfix
        for (char c : s) {
            if (isalnum(c)) {
                result += c;
            } else if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                // Pop till '('
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // pop '('
            } else {
                while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        // Step 4: Reverse result to get prefix
        reverse(result.begin(), result.end());
        
        return result;
    }
};
