/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */

void insertIntoStack(stack<int>& st, int& x){
    if(st.empty()) {
        st.push(x);
        return;
    }
    
    if(st.top() > x) {
        int temp = st.top();
        st.pop();
        insertIntoStack(st, x);
        st.push(temp);
    }else{
        st.push(x);
    }
}

void solve(stack<int>& st){
    if(st.size() == 1) return;
    
    int temp = st.top();
    st.pop();
    solve(st);
    insertIntoStack(st, temp);
}

void SortedStack ::sort() {
    solve(s);
}