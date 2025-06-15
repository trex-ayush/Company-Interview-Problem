// Company tags: Adobe, Amazon, Apple, Bloomberg, eBay, Intuit, MakeMyTrip, Meta, Microsoft, Oracle, Salesforce, Sprinklr, TikTok, Uber, Visa, Yahoo, Zoho
class Solution {
public:
    // Approach 1: T.C: O(n) S.C: O(2n)
    // int longestValidParentheses(string s) {
    //     int n = s.length();
    //     stack<int> st;
    //     vector<bool> valid(n, false);

    //     // First pass: mark all valid pairs
    //     for (int i = 0; i < n; i++) {
    //         if (s[i] == '(') {
    //             st.push(i);
    //         } else {
    //             if (!st.empty()) {
    //                 valid[i] = true;
    //                 valid[st.top()] = true;
    //                 st.pop();
    //             }
    //         }
    //     }

    //     // Second pass: find the longest streak of 'true' in valid[]
    //     int maxLen = 0, currLen = 0;
    //     for (bool v : valid) {
    //         if (v) {
    //             currLen++;
    //             maxLen = max(maxLen, currLen);
    //         } else {
    //             currLen = 0;
    //         }
    //     }

    //     return maxLen;
    // }

    /* ------------------------------------------------- */
    // Approach 2: T.C: O(n) S.C: O(n)
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int> st;
        st.push(-1);
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if(st.empty()) st.push(i);
                else maxLen = max(maxLen, i - st.top());
            }
        }

        return maxLen;
    }
};