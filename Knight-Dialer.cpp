class Solution {
public:
    const int mod = 1e9+7;
    unordered_map<int, vector<int>> mpp = {
        {0, {4, 6}},
        {1, {6, 8}},
        {2, {7, 9}},
        {3, {4, 8}},
        {4, {0, 3, 9}},
        {6, {0, 1, 7}},
        {7, {2, 6}},
        {8, {1, 3}},
        {9, {2, 4}}
    };
    int t[5001][10];

    int solve(int n, int cell) {
        if (n == 0) return 1;
        if (t[n][cell] != -1) return t[n][cell];

        int ans = 0;
        for (auto& neigh : mpp[cell]) {
            ans = (ans + solve(n - 1, neigh)) % mod;
        }

        return t[n][cell] = ans;
    }

    int knightDialer(int n) {
        memset(t, -1, sizeof(t));
        int result = 0;
        for (int i = 0; i <= 9; i++) {
            result = (result + solve(n - 1, i)) % mod;
        }
        return result;
    }
};
