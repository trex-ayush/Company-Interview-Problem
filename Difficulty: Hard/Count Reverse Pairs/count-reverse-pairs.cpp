class Solution {
public:
    int f(int l, int r, vector<int> &arr) {
        if(r - l <= 1) return 0;
        int m = (l + r) / 2, ans = 0;
        ans += f(l, m, arr);
        ans += f(m, r, arr);
        for(int i = l, j = m; i < m && j < r; ) {
            if(arr[i] > 2 * arr[j]) {
                ans += (m - i); j++;
            } else i++;
            
        }
        vector<int> tmp(r - l, 0);
        for(int i = l, j = m, k = 0; i < m || j < r; ) {
            if(j >= r || (i < m && arr[i] < arr[j])) tmp[k++] = arr[i++];
            else tmp[k++] = arr[j++];
        } 
        for(int i = 0; i < (r - l); i++) arr[i + l] = tmp[i];
        return ans;
    }
    int countRevPairs(vector<int> &arr) {
        return f(0, arr.size(), arr);
    }
};