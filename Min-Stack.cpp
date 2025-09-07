// Company tags: Agoda, Cisco, DE Shaw, Flipkart, Intuit, Lyft, Nvidia, Oracle, Palo Alto Networks, PayPal, Paytm, Qualcomm, Salesforce, ServiceNow, Snap, Snowflake, Splunk, Tinkoff, Walmart Labs, Yandex, Zenefits, LinkedIn
class MinStack {
public:
    vector<pair<int,int>> st;  // {element, minElement}

    // TC: O(1), SC: O(1)
    MinStack() {}

    // TC: O(1), SC: O(1) per operation
    void push(int x) {
        if(st.empty()) st.push_back({x,x});
        else if(x < st.back().second){
            st.push_back({x, x});
        } else {
            st.push_back({x, st.back().second});
        }
    }

    // TC: O(1), SC: O(1)
    void pop() {
        if(!st.empty()) st.pop_back();
    }

    // TC: O(1), SC: O(1)
    int top() {
        if(st.empty()) return -1;
        return st.back().first;
    }

    // TC: O(1), SC: O(1)
    int getMin() {
        if(st.empty()) return -1;
        return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
