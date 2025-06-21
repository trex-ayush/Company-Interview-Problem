class Solution {
public:
    int solve(int st, int en, vector<int>& cuts, vector<vector<int>>& t){
        if(en - st <= 1) return 0;

        if(t[st][en] != -1) return t[st][en];

        int ans = INT_MAX;

        for(int i = st + 1; i < en; i++){
            int cost = cuts[en] - cuts[st];
            cost += solve(st, i, cuts, t) + solve(i, en, cuts, t);
            ans = min(ans, cost);
        }

        return t[st][en] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int m = cuts.size();
        vector<vector<int>> t(m+2, vector<int>(m+2, -1));
        return solve(0, m-1, cuts, t);
    }
};