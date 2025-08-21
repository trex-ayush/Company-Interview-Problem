class Solution {
  public:
    bool isPossible(vector<int> &stalls, int k , int idx){
        int n = stalls.size();
        int currCowPlaced = 1;
        int lastPos = stalls[0];
        
        for(int i = 1; i < n; i++){
            if(abs(stalls[i] - lastPos) >= idx){
                currCowPlaced++;
                if(currCowPlaced == k) return true;
                lastPos = stalls[i];
            }
        }
        return currCowPlaced == k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(begin(stalls) , end(stalls));
        int st = 1;
        int en = stalls[n - 1] - stalls[0];
        int ans = 0;
        while(st <= en){
            int mid = st + (en-st)/2;
            if(isPossible(stalls,k,mid)){
                ans = mid;
                st = mid + 1;
            }else {
                en  = mid - 1;
            }
        }
        return ans;
    }
    int maxMinDiff(vector<int>& arr, int k) {
        return aggressiveCows(arr,k);
    }
};
