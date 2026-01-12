
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> ans;
        deque<int> dq;
        int i=0,j=0;
        int n=arr.size();
        
        while(j<n){
            while (!dq.empty() && dq.back() < arr[j]) {
                dq.pop_back();
            }
            dq.push_back(arr[j]);
            
            if(j-i+1<k){
                j++;
            }else if(j-i+1==k){
                ans.push_back(dq.front());
                if(arr[i]==dq.front()){
                    dq.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};

