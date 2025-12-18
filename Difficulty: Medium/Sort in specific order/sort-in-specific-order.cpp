class Solution {
  public:
    void sortIt(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n - 1;
        
        while (l <= r) {
            if (arr[l] % 2 != 0) {
                l++;
            } else if (arr[r] % 2 == 0) {
                r--;
            } else {
                swap(arr[l], arr[r]);
                l++;
                r--;
            }
        }
        
        // l is the count of odd numbers
        sort(arr.begin(), arr.begin() + l, greater<int>());
        sort(arr.begin() + l, arr.end());
    }
};
