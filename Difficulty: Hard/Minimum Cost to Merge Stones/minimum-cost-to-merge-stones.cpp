class Solution {
  private:
    int rangeSum(vector<int> &prefix,int i,int j) {
        return prefix[j+1]-prefix[i];
    }
    
  public:
    int mergeStones(vector<int> &stones, int k) {
        int n = stones.size();
        
        // Step 1: Feasibility Check
        if((n-1) % (k-1)!=0){
            return -1;
        }
        
        // Step 2: Prefix Sum
        vector<int> prefix(n+1,0);
        
        for (int i=0; i<n;i++){
            prefix[i+1]=prefix[i]+stones[i];
        } 
            
        
        // Step 3: DP initialization
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Step 4: Process by segment length
        for(int len=k;len<=n;len++){
            for(int i=0;i+len<=n;i++){
                int j=i+len-1;
                dp[i][j]=INT_MAX;
                
                // Try merging subparts in steps of (k - 1)
                for(int m=i;m< j;m+=(k-1)){
                    dp[i][j]=min(dp[i][j],dp[i][m] + dp[m+1][j]);
                }
                
                // If this segment can form exactly 1 pile, add cost
                if((len-1) % (k-1)==0){
                    dp[i][j]+=rangeSum(prefix,i,j);
                }
            }
        }
        
        return dp[0][n-1];
    }
};