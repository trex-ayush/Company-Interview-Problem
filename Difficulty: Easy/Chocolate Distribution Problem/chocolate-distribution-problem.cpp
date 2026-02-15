class Solution {
  public:
    int findMinDiff(vector<int> arr, int m) {
        sort(arr.begin(), arr.end());
        int mini = INT_MAX;
        
        int i = 0;
        int j = 0;
        while(j < arr.size()){
            while(j - i + 1 < m){
                j++;
            }
            mini = min(mini , arr[j] - arr[i]);
            i++;
            j++;
        }
        return mini;
    }
};
