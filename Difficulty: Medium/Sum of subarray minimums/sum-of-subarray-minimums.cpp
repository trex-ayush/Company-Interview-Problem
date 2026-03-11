class Solution {
  public:
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int>  st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return result;
    }
    
    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int>  st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return result;
    }

    int sumSubMins(vector<int>& arr) {
        int n   = arr.size();
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);
        
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            int leftD = i - NSL[i];
            int rightD = NSR[i] - i;
            sum +=  arr[i] * leftD * rightD;
        }
        return sum;
    }
};
