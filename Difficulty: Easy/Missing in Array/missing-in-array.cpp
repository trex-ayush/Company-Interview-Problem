class Solution {
  public:
    int missingNum(vector<int>& arr) {
        long long int  n = arr.size();
        
        long long int expectedSum = ((n+1)*(n+2))/2;
        long long int  actualSum = 0;
        
        for(int i = 0; i < n ; i++){
            actualSum += arr[i];    
        }
        long long int ans = expectedSum - actualSum;

        return ans;
    }
};