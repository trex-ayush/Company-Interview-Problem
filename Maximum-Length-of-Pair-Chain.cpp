// Company tags: Swiggy
class Solution {
public:
    // Approach: bottom up
    // T.C: O(n^2)
    // S.C: O(n)
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<int> t(n, 1);
        int maxLen = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(pairs[i][0] > pairs[j][1]){
                    t[i] = max(t[i], 1 + t[j]);
                    maxLen = max(maxLen, t[i]);
                }
            }
        }
        return maxLen;
    }

    /*------------------------------------------*/
    // Approach : recursive + memo
    // T.C: O(n^2)
    // S.C: O(n^2)

    // vector<vector<int>> t;
    // int solve(vector<vector<int>>& pairs, int i, int prev){
    //     if(i == pairs.size()) return 0;

    //     if(t[i][prev+1] != -1) return t[i][prev+1];

    //     int skip = solve(pairs, i+1, prev);

    //     int take = 0;
    //     if(prev == -1 || pairs[i][0] > pairs[prev][1]){
    //         take = 1 + solve(pairs, i+1, i);
    //     }

    //     return t[i][prev+1] = max(take, skip);
    // }
    // int findLongestChain(vector<vector<int>>& pairs) {
    //     int n = pairs.size();
    //     t.resize(n+1, vector<int>(n+1, -1));
    //     sort(pairs.begin(), pairs.end());
    //     return solve(pairs, 0, -1);
    // }
};