class Solution {
  public:
    int minCandy(vector<int> &arr) {
        int n=arr.size();
        
        vector<int>pre(n, 1), suf(n, 1);
        
        for(int i=1; i<n; i++){
            if(arr[i-1]<arr[i]) pre[i]=pre[i-1]+1;
        }
        
        for(int i=n-2; i>=0; i--){
            if(arr[i+1]<arr[i]) suf[i]=suf[i+1]+1;
        }
        
        int sum=0;
        
        for(int i=0; i<n; i++){
            sum+=max(pre[i], suf[i]);
        }
        
        return sum;
    }
};
