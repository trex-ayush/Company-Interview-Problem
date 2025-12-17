class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        
        if (n == 0) return ans; 
        
        sort(arr.begin(),arr.end());
        
        int start = arr[0][0];
        int end   = arr[0][1];
        
        for(int i = 1; i < n; i++){
            int st = arr[i][0];
            int en = arr[i][1];
            
            if(st <= end){
                end = max(end , en);
            }else{
                ans.push_back({start , end});
                start = st;
                end = en;
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};