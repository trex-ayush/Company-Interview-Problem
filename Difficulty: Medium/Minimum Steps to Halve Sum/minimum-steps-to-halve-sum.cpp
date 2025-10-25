class Solution {
  public:
    int minOperations(vector<int>& arr) {
        priority_queue<double> pq;
        double total = 0;
        for (double a : arr) {
            total += a;
            pq.push(a);
        }
        
        double target = total / 2.0;
        double reduced = 0;
        int cnt = 0;
        
        while (reduced < target) {
            double x = pq.top(); pq.pop();
            reduced += x / 2.0;
            pq.push(x / 2.0);
            cnt++;
        }
        
        return cnt;
    }
};