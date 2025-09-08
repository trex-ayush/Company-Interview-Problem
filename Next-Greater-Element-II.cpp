// Companyy tags: FLipkart, Zeta
class Solution {
public:
    // T.C: O(n)
    // S.C: O(n)
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;
        
        for(int i = 2*n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i%n]) st.pop();
            
            if(st.empty()) res[i%n] = -1;
            else res[i%n] = arr[st.top()];
            
            st.push(i%n);
        }
        
        return res;
    }
};