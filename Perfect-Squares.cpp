1/* 
2    Company tags: Accenture, Citadel, Walmart Labs, Yandex
3*/
4class Solution {
5public:
6    // T.C: O(n * sqrt(n))
7    // S.C: O(n)
8    int t[10001];
9    int solve(int n){
10        if(n == 0) return 0;
11        if(t[n] != -1) return t[n];
12
13        int mini = INT_MAX;
14        for(int i = 1; i * i <= n; i++){
15            int res = 1 + solve(n - i*i);
16            mini = min(mini, res);
17        }
18
19        return t[n] = mini;
20    }
21    int numSquares(int n) {
22        memset(t, -1, sizeof(t));
23        return solve(n);
24    }
25};