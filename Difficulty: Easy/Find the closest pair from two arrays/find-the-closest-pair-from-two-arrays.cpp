class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int n = arr1.size();
        int m = arr2.size();
        
        int a = 0, b = 0;
        int i = 0;
        int j = m- 1;
        int check = INT_MAX;
        
        while(i < n && j >= 0){
            int sum = arr1[i] + arr2[j];
            int diff = abs(sum - x);
            if(diff < check){
                a = arr1[i];
                b = arr2[j];
                if(diff == 0) return {a, b};
                check = diff;
            }
            if(sum < x) i++;
            else j--;
        }
        return {a ,b};
    }
};