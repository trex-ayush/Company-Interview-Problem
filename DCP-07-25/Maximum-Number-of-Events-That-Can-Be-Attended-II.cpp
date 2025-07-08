/* Approach 1 -> Binary Search */
class Solution {
public:
    // Time Complexity : O(n * k * logn)
    // Space Complexity: O(n * k)
    int bs(vector<vector<int>>& events, int idx){
        int n = events.size();
        int result = n;
        int st = idx + 1;
        int en = n - 1;

        while(st <= en){
            int mid = st + (en - st)/2;

            if(events[mid][0] > events[idx][1]){
                result = mid;
                en = mid - 1;
            }else st = mid + 1;
        }

        return result;
    }
    int solve(vector<vector<int>>& events, int idx, int k, vector<vector<int>>& t){
        int n = events.size();
        if(idx >= n || k == 0) return 0;

        if(t[idx][k] != -1) return t[idx][k];

        int skip = solve(events, idx + 1, k, t);
        int take = events[idx][2];
        int j = bs(events, idx);  // O(log n)
        take += solve(events, j, k - 1, t);

        return t[idx][k] = max(take, skip);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> t(n+1, vector<int>(k+1, -1));

        sort(events.begin(), events.end());  // O(nlogn)

        return solve(events, 0, k, t);  // O(2^n)
    }
};


/* Approach 2 -> Linear Search */
class Solution {
public:
    // Time Complexity : O(n * k * n)
    // Space Complexity: O(n * k)
    int solve(vector<vector<int>>& events, int idx, int k, vector<vector<int>>& t){
        int n = events.size();
        if(idx >= n || k == 0) return 0;

        if(t[idx][k] != -1) return t[idx][k];

        int skip = solve(events, idx + 1, k, t);
        int take = events[idx][2];
        int j;
        for(j = idx + 1; j < n; j++){ // O(n)
            if(events[j][0] > events[idx][1]) break;
        }
        take += solve(events, j, k - 1, t);

        return t[idx][k] = max(take, skip);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> t(n+1, vector<int>(k+1, -1));

        sort(events.begin(), events.end());  // O(nlogn)

        return solve(events, 0, k, t);  // O(2^n)
    }
};
