class MyStack {
  public:
    vector<int> arr;
    void push(int x) {
        arr.push_back(x);
    }

    int pop() {
        if(arr.empty()){
            return -1;
        }
        int val = arr.back();
        arr.pop_back();
        return val;
    }
};