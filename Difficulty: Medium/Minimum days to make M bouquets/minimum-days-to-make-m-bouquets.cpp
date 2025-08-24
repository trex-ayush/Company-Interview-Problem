class Solution {
  public:
    bool check(vector<int>& arr, int &k, int &m, int &mid) {
        int ctr = 0, t = 0;
        
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] <= mid) {
                t++;
                
                if(t && t % k == 0) ctr++, t = 0;
            } else {
                t = 0;
            }
        }

        return ctr >= m;
    }

    int minDaysBloom(vector<int>& arr, int k, int m) {
        int l = 0;
        int r = *max_element(arr.begin(), arr.end());
        int ans = -1;
        
        while(l <= r) {
            int mid = (l + r) / 2;
            
            if(check(arr, k, m, mid)) {
                ans = mid;
                r = mid - 1;
            } 
            else l = mid + 1;
        }

        return ans;
    }
};