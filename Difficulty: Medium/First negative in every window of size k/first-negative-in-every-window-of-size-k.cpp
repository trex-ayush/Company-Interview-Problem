class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result;
        
        deque<int> dq;   // element
        
        int j = 0;
        int i = 0;
        
        while(j < n){
            if(arr[j] < 0){
                dq.push_back(arr[j]);
            }
            
            if(j - i + 1 == k){
                if(!dq.empty()) result.push_back(dq.front());
                else result.push_back(0);
                
                if (!dq.empty() && arr[i] < 0) {
                    dq.pop_front();
                }
                i++;
            }
            j++;
        }
        
        return result;
    }
};