class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n,-1);
        vector<int>pre(n);
        pre[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            pre[i]=min(arr[i],pre[i+1]);
        }
        for(int i=0;i<n-1;i++){
            int ind=upper_bound(pre.begin(),pre.end(),arr[i]-1)-pre.begin();
            if(ind>i){
                ans[i]=ind-1;
            }
        }
        return ans;
    }
};