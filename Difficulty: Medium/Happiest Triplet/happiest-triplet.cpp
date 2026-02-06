class Solution {
public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        int i = 0, j = 0, k = 0;
        int diff = INT_MAX;
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        
        vector<int> ans;
        while (i < a.size() && j < b.size() && k < c.size()) {
            int mini = min({a[i], b[j], c[k]});
            int maxi = max({a[i], b[j], c[k]});
            if (diff > (maxi - mini)) {
                diff = maxi - mini;
                ans = {a[i], b[j], c[k]};
            }
            if (mini == a[i]) i++;
            else if (mini == b[j]) j++;
            else k++;
        }
        sort(ans.begin(), ans.end(), greater<int>());
        return ans;
    }
};