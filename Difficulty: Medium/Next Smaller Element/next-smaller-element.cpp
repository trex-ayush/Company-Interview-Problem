class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        
        stack<int> st;
        vector<int> res(n, -1);
        
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop(); 
            }
            if(!st.empty()) res[i] = st.top();
            st.push(arr[i]);
        }
        
        return res;
    }
};   