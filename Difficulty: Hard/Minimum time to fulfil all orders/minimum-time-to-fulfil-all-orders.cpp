class Solution {
  public:
    int minTime(vector<int>& ranks, int n) {
        int minr=101;
        for (int i : ranks){
            minr=min(minr,i);
        }
        int ans=0;
        int s=0,e=(minr*n*(n+1))/2;
        int m;
        
        while(s<=e){
            m=s+(e-s)/2;
            int don=0;
            for (int r : ranks) {
                int time = 0;
                int k = 1;
                while (time + k * r <= m) {
                    time += k * r;
                    don++;
                    k++;
                    if (don >= n) break;
                }
                if (don >= n) break;
            }
            if(don>=n){
                ans=m;
                e=m-1;
            }
            else
                s=m+1;
        }
        return ans;
    }
};