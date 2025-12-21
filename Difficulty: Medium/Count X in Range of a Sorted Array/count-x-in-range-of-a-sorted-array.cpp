class Solution {
  public:
    int bs(vector<int>& arr, int i, int j, int k){
        int lower = -1, upper = -1;
        
        // lower bound
        int st = i, en = j;
        while(st <= en){
            int mid = st + (en - st) / 2;
            if(arr[mid] >= k){
                if(arr[mid] == k) lower = mid;
                en = mid - 1;
            } else {
                st = mid + 1;
            }
        }
    
        // upper bound
        st = i; en = j;
        while(st <= en){
            int mid = st + (en - st) / 2;
            if(arr[mid] <= k){
                if(arr[mid] == k) upper = mid;
                st = mid + 1;
            } else {
                en = mid - 1;
            }
        }
        
        if(lower == -1) return 0; // x not found
        return upper - lower + 1;
    }

    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int q = queries.size();
        
        vector<int> res(q);
        
        for(int i = 0; i < q; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];
            res[i] = bs(arr, l, r, x);
        }
        
        return res;
    }
};