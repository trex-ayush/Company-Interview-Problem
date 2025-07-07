class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> st;
        
        for(int i = 2*n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i%n]){
                st.pop();
            }
            
            result[i%n] = st.empty() ? -1 : arr[st.top()];
            st.push(i%n);
        }
        
        return result;
    }
};