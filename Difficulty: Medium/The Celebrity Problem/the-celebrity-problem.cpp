class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        
        stack<int> st;
        
        for(int i = 0; i < n; i++) st.push(i);
        
        while(st.size() > 1){
            int i = st.top();
            st.pop();
            int j = st.top();
            st.pop();
            
            if(mat[i][j] == 1){
                // i know j
                st.push(j);
            }else{
                // j know i
                st.push(i);
            }
        }
        
        int canBeCeleb = st.top();
        st.pop();
        
        for(int i = 0; i < n; i++){
            if(i != canBeCeleb && (mat[canBeCeleb][i] == 1 || mat[i][canBeCeleb] == 0)) return -1;
        }
        
        return canBeCeleb;
    }
};