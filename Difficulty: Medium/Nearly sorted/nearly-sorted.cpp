class Solution {
public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int j = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            pq.push(arr[i]);
            if (pq.size() > k) {
                arr[j] = pq.top();
                pq.pop();
                j++;
            }
        }
        while (pq.size() && j < n) {
            arr[j] = pq.top();
            pq.pop();
            j++;
        }
    }
};