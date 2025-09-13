class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &arr) {
        stack<int> st;
        
        for(auto& a : arr){
            bool isDestroyed  = false;
            while(!st.empty() && a < 0 && st.top() > 0){
                int sum = st.top() + a;
                if(sum < 0){
                    st.pop();
                }else if(sum > 0){
                    isDestroyed = true;
                    break;
                }else{
                    isDestroyed = true;
                    st.pop();
                    break;
                }
            }
            if(isDestroyed == false) st.push(a);
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