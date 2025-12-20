class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        int n = arr.size();
        int st = 0;
        int en = n - 1;
        
        int res = n;
        
        while(st <= en){
            int mid = st + (en - st)/2;
            if(arr[mid] == k) return mid;
            else if(arr[mid] > k) {
                res = mid;
                en = mid - 1;
            }else st = mid + 1;
        }
        
        return res;
    }
};