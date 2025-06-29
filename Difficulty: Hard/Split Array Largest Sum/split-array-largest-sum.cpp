class Solution {
  public:
    bool isPossible(vector<int>& arr, int k, int& mid){
        int n = arr.size();
        int split = 1;
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            if (arr[i] > mid) return false;
            if (sum + arr[i] > mid) {
                split++;
                sum = arr[i];
                
                if(split > k) return false;
            } else {
                sum += arr[i];
            }
        }
        return split <= k;
    }
    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        int maxElement = -1;
        int totalSum = 0;
        
        for(int i = 0; i < n; i++){
            totalSum += arr[i];
            if(arr[i] > maxElement) maxElement = arr[i];
        }
        
        int st = maxElement;
        int en = totalSum;
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