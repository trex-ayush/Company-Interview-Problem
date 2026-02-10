class Solution {
  public:
    bool isPossible(vector<int>& arr, int k, int& val){
        int n = arr.size();
        int count = 0;  // kitna time lga
        
        for(int i = 0; i < n; i++){
            if(arr[i] % val == 0) count += arr[i]/val;
            else count += ((arr[i]/val) + 1);
        }
        
        return count <= k;
    }
    int kokoEat(vector<int>& arr, int k) {
        int n = arr.size();
        
        int st = 1;
        int en = *max_element(arr.begin(), arr.end());
        
        int ans = 0;
        
        while(st <= en){
            int mid = st + (en - st)/2;
            
            if(isPossible(arr,k,mid)){
                ans = mid;
                en = mid - 1;
            }else st = mid + 1;
        }
        return ans;
    }
};