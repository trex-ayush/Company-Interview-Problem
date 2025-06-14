class Solution {
  public:
    bool isPossible(vector<int>& arr, int& k,  int& mid){
        int n = arr.size();
        int count = 0;
        
        for(int i = 0; i < n; i++){
            count += ceil((arr[i]*1.0)/mid);
            if(count > k) return false;
        }
        
        return count <= k;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int st = 1;
        int en = arr[n-1];
        int ans = -1;
        
        while(st <= en){
            int mid = st + (en - st)/2;
            
            if(isPossible(arr, k, mid)){
                ans = mid;
                en = mid - 1;
            }else st = mid + 1;
        }
        
        return ans;
    }
};
