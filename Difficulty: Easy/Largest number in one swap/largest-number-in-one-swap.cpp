class Solution {
  public:
    string largestSwap(string &s) {
        int n = s.length();
        vector<int> maxRight(n); //stores the index of max element to right
        
        maxRight[n-1] = n-1;
        for(int i = n-2; i >= 0; i--) {
            int rightMaxIdx = maxRight[i+1];
            int rightMaxElement = s[rightMaxIdx];
            
            maxRight[i] = (s[i] > rightMaxElement) ? i : rightMaxIdx;
        }
        
        for(int i = 0; i < n; i++) {
            int maxRightIdx = maxRight[i];
            int maxRightElement = s[maxRightIdx];
            if(s[i] < maxRightElement) {
                swap(s[i], s[maxRightIdx]);
                return s;
            }
        }
        
        return s;
    }
};

 