// Company tags: Agoda, ByteDance, Cisco, Coupang, eBay, Geico, Goldman Sachs, Huawei, Intuit, Salesforce, ServiceNow, Snowflake, Splunk, Tinkoff, Walmart Labs, Wix, Yelp, Zomato, Zoho
class Solution {
public:
    // Time Complexity  : O(m) (m = length of output string)
    // Space Complexity : O(n + m), the stack can hold O(n) substrings and numbers.
    string decodeString(string s) {
        stack<string> st;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                int j = i;
                while (j < n && isdigit(s[j])) j++;
                st.push(s.substr(i, j - i));
                i = j - 1;
            } else if (s[i] == '[' || isalpha(s[i])) {
                st.push(string(1, s[i]));
            } else if (s[i] == ']') {
                string decoded = "";
                while (!st.empty() && st.top() != "[") {
                    decoded = st.top() + decoded;
                    st.pop();
                }
                if (!st.empty() && st.top() == "[") {
                    st.pop();
                }
                int repeat = 1;
                if (!st.empty()) {
                    repeat = stoi(st.top());
                    st.pop();
                }
                string temp = "";
                for (int k = 0; k < repeat; ++k) {
                    temp += decoded;
                }
                st.push(temp);
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
