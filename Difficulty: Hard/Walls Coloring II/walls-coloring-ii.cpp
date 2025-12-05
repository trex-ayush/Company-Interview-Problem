class Solution {
  public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        int k = costs[0].size();
        if(k==1 and n!=1)return -1;
        int dp[n][k];
        for(int i=0;i<k;i++){
            dp[0][i]=costs[0][i];
        }
        int ans = INT_MAX;
        for(int i=1;i<n;i++){
            int first=INT_MAX,second=INT_MAX;
            for(int j=0;j<k;j++){
                if(dp[i-1][j]<first){
                    second=first;
                    first=dp[i-1][j];
                }
                else if(dp[i-1][j]<second){
                    second=dp[i-1][j];
                }
            }
            for(int j=0;j<k;j++){
                if(dp[i-1][j]!=first){
                    dp[i][j]=costs[i][j]+first;
                }
                else dp[i][j]=costs[i][j]+second;
            }
        }
        for(int i=0;i<k;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};