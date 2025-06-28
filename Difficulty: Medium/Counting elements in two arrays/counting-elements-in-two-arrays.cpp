class Solution {
  public:
    int bs(vector<int>& arr, int k){
        int n = arr.size();
        int st = 0;
        int en = n - 1;
        int count = 0;
        
        while(st <= en){
            int mid = st + (en - st)/2;
            if(arr[mid] <= k){
                count = mid + 1;
                st = mid + 1;
            }else en = mid - 1;
        }
        return count;
    }
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        
        sort(b.begin(), b.end());
        
        for(int i = 0; i < a.size(); i++){
            int k = bs(b, a[i]);
            ans.push_back(k);
        }
        
        return ans;
    }
};