class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &arr) {
        stack<int> st;
        
        for(auto& a : arr){
            while(!st.empty() && a < 0 && st.top() > 0){
                int sum = st.top() + a;
                if(sum < 0){
                    st.pop();
                }else if(sum > 0){
                    a = 0;
                }else{
                    a = 0;
                    st.pop();
                }
            }
            if(a != 0) st.push(a);
        }
        
        int s = st.size();
        vector<int> res(s);
        int i = 0;
        while(!st.empty()){
            res[i++] = st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};