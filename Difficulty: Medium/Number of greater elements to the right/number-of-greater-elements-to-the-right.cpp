class Solution {
public:
    vector<int> count_NGE(vector<int>& arr, vector<int>& indices) {
        vector<int> ans;
        int n = arr.size();
        
        for (auto i : indices) {
            int c = 0;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    c++;
                }
            }
            ans.push_back(c);
        }
        
        return ans;
    }
};