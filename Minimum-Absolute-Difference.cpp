1/*
2    Company tags: Agoda, IBM, J.P. Morgan, Morgan Stanley, PayPal
3*/
4class Solution {
5public:
6    // T.C: O(n * logn) due to sorting
7    // S.C: O(1) if we ignore the space used by the result vector
8    vector<vector<int>> minimumAbsDifference(vector<int>& A) {
9        sort(A.begin(), A.end());
10        int minDiff = INT_MAX;
11        vector<vector<int>> res;
12
13        for (int i = 1; i < A.size(); i++) {
14            int diff = A[i] - A[i - 1];
15            if (diff < minDiff) {
16                minDiff = diff;
17                res = {};
18                res.push_back({A[i - 1], A[i]});
19            } else if (diff == minDiff) {
20                res.push_back({A[i - 1], A[i]});
21            }
22        }
23        return res;
24    }
25};