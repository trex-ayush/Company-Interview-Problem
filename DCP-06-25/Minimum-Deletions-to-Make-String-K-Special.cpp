// Company tags: DE Shaw
class Solution {
public:
    // Approach 1
    // T.C: O(n + 26*26) = O(n)
    // S.C: O(26) = O(1)
    int minimumDeletions(string word, int k) {
        vector<int> mpp(26,0);

        for(auto& ch : word) mpp[ch - 'a']++;  // O(n)

        int ans = INT_MAX;

        for(int i = 0; i < 26; i++){  // O(26)
            if (mpp[i] == 0) continue;
            int freq = mpp[i];
            int deletion = 0;

            for(int j = 0; j < 26; j++){ // O(26)
                if(i == j) continue;
                if(mpp[j] < freq){
                    deletion += mpp[j];
                }else if(mpp[j] - freq > k){
                    deletion += (mpp[j] - (freq + k));
                }
            }

            ans = min(ans, deletion);
        }
        return ans;
    }
};