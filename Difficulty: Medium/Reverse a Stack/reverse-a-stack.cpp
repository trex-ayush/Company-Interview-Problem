
class Solution {
  public:
    void insertAtBottom(stack<int>& st, int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        int temp = st.top();
        st.pop();
        insertAtBottom(st, x);
        st.push(temp);
    }
    void reverse(stack<int> &st) {
        if(st.size() == 1) return;
        
        int temp = st.top();
        st.pop();
        reverse(st);
        insertAtBottom(st, temp);
    }
};