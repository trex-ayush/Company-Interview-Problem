class Solution {
  public:
    bool isPossible(vector<int>& arr, int n ,int k , int mid){
        int timeSum = 0;
        int count = 1;
        
        for(int i = 0; i < n; i++){
            if(arr[i] > mid) return false;
            
            if(arr[i] + timeSum > mid){
                count++;
                timeSum = arr[i];
                if(count > k) return false;
            }else timeSum += arr[i];
        }
        return true;
    }
  
    int minTime(vector<int>& arr, int k) {
        int n = arr.size();
        
        int start = 0;
        int end = 0;
        int ans = -1;
        
        for(int i = 0 ; i < n ; i++){
            end += arr[i];
        }
        
        while(start <= end){
            int mid = start + (end - start)/2;
            if(isPossible(arr, n, k, mid)){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};