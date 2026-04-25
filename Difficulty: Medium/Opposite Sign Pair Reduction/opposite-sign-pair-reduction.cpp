class Solution {
  public:
    vector<int> reducePairs(vector<int> &arr) {
        stack<int> st;

        for (int a : arr) {
            while (!st.empty() && st.top() * a < 0) {
                int b = st.top();
                st.pop();

                if (abs(a) > abs(b)) {
                    // a survives, continue reducing with new top
                    continue;
                }
                else if (abs(a) < abs(b)) {
                    // b survives
                    a = b;
                }
                else {
                    // both removed
                    a = 0;
                }

                break;
            }

            if (a != 0) st.push(a);
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};