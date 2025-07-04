class Solution {
  public:
    int countAtMostK(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;
        int i = 0;
        int j = 0;
        int result = 0;
        
        while (j < n) {
            mp[arr[j]]++;
            
            while (mp.size() > k) {
                mp[arr[i]]--;
                if (mp[arr[i]] == 0) {
                    mp.erase(arr[i]);
                }
                i++;
            }
            
            result += (j - i + 1);
            j++;
        }
        return result;
    }
};