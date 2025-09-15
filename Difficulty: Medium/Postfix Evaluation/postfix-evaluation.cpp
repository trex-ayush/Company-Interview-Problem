class Solution {
public:
    bool isOperator(const string& s) {
        return s == "+" || s == "-" || s == "*" || s == "/" || s == "^";
    }

    int floorDiv(int a, int b) {
        int q = a / b;
        if ((a ^ b) < 0 && a % b != 0) q--;
        return q;
    }

    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;

        for (auto& token : arr) {
            if (isOperator(token)) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(floorDiv(a, b));
                else if (token == "^") st.push(pow(a, b));
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
