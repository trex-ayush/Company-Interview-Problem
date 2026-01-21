class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        stack<int> st;
        vector<int> ans;
        for (int i=0;i<arr.size();i++) {
            int len = 1;
            while (!st.empty() && arr[i] >= arr[st.top()]) {
                len = max(len, i - st.top() + ans[st.top()]);
                st.pop();
            }
            
            ans.push_back(len);
                
            st.push(i);
        }
        
        return ans;
    }
};
