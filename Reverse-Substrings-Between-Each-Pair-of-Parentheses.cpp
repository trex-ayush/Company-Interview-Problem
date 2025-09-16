// Company Tags  : META, AMAZON, AGODA
class Solution {
public:
    // T.C: O(n)
    // S.C: O(n)
    string reverseParentheses(string s) {
        stack<string> st;

        for (char c : s) {
            if (c == ')') {
                string temp = "";
                while (!st.empty() && st.top() != "(") {
                    temp = st.top() + temp;
                    st.pop();
                }
                if (!st.empty()) st.pop();
                reverse(temp.begin(), temp.end());
                st.push(temp);
            } else {
                st.push(string(1, c));
            }
        }

        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};