class Solution {
    public:
    int bs(int s, int e, vector<int>&arr, int x){
        int lo=s, hi=e, ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]<=x){
                ans=mid;
                lo=mid+1;
            }else hi=mid-1;
        }
        return ans==-1?0:ans-s+1;
    }
    int countLessEqual(vector<int>& arr, int x) {
        int n=arr.size();
        int cnt=0;
        
        int lo=0, hi=n-1;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[lo]<=arr[mid]){
                cnt+=bs(lo, mid, arr, x);
                lo=mid+1;
            }else{
                cnt+=(bs(mid, hi, arr, x));
                hi=mid-1;
            }
        }
        
        return cnt;
    }
};