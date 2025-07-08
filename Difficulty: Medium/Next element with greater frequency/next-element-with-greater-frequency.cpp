class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        unordered_map<int,int> mpp;
        stack<int> st;
        
        for(auto& a : arr) mpp[a]++;
        
        for(int i = n - 1; i >= 0; i--){
            if(st.empty()) st.push(arr[i]);
            while(!st.empty() && mpp[st.top()] <= mpp[arr[i]]) st.pop();
            if(!st.empty() && mpp[st.top()] > mpp[arr[i]]){
                result[i] = st.top();
            } 
            st.push(arr[i]);
        }
        
        return result;
    }
};
