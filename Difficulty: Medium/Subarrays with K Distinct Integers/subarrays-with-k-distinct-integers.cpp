class Solution {
  public:
    int atMostK(vector<int>& s, int k) {
        int n = s.size();
        unordered_map<int, int> mpp;
        int i = 0;
        int j = 0;
        int count = 0;
        
        while(j < n){
            if (mpp[s[j]] == 0) k--;
            mpp[s[j]]++;
            
            while (k < 0) {
                mpp[s[i]]--;
                if (mpp[s[i]] == 0) k++;
                i++;
            }
            
            count += (j - i + 1);
            j++;
        }
        
        return count;
    }

    int exactlyK(vector<int>& s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};
