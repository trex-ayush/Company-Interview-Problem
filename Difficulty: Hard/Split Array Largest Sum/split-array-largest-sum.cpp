class Solution {
  public:
    bool isPossible(vector<int>& arr, int k, int pages){
        int studentCount = 1;
        int totalPages = 0;
        
        for(int i = 0; i < arr.size(); i++){
            
            if(totalPages + arr[i] <= pages){
                totalPages += arr[i];
            }else{
                studentCount++;
                totalPages = arr[i];
            }
            if(studentCount > k || arr[i] > pages) return false;
        }
        return true;
    }
    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        
        int totalPages = 0;
        int st = 0;
        
        for(auto& a : arr) {
            st = max(a, st);
            totalPages += a;
        }
        
        int en = totalPages;
        int ans = -1;
        
        while(st <= en){
            int mid = st + (en - st)/2;
            
            if(isPossible(arr, k, mid)){
                ans = mid;
                en = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        
        return ans;
    }
};