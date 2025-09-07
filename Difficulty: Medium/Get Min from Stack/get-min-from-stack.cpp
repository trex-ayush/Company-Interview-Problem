class Solution {
  public:
    vector<pair<int,int>> st;  // {element, minElement}
    Solution() {}
    
    void push(int x) {
        if(st.empty()) st.push_back({x,x});
        else if(x < st.back().second){
            st.push_back({x, x});
        }else st.push_back({x, st.back().second});
    }

    void pop() {
        if(!st.empty()) st.pop_back();
    }

    int peek() {
        if(st.empty()) return -1;
        return st.back().first;
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return st.back().second;
    }
};