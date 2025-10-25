class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if(k > q.size()) return q;
        stack<int> st;
        while(k--){
            st.push(q.front());
            q.pop();
        }
        queue<int> q1;
        while(!st.empty()){
            q1.push(st.top());
            st.pop();
        }
        while(!q.empty()){
            q1.push(q.front());
            q.pop();
        }
        return q1;
    }
};