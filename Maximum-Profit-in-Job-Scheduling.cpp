// Company tags: Airbnb, Akuna Capital, Databricks, DE Shaw, DoorDash, Flipkart, PhonePe, Pinterest, Snowflake, Sprinklr, Swiggy, Verkada, Zeta
class Solution {
public:
    // Time Complexity : O(n log n)
    // Space Complexity: O(n)
    int bs(vector<vector<int>>& events, int idx){
        int n = events.size();
        int result = n;
        int st = idx + 1;
        int en = n - 1;

        while(st <= en){
            int mid = st + (en - st)/2;

            if(events[mid][0] >= events[idx][1]){
                result = mid;
                en = mid - 1;
            }else st = mid + 1;
        }

        return result;
    }

    int solve(vector<vector<int>>& events, int idx, vector<int>& t){
        int n = events.size();
        if(idx >= n) return 0;

        if(t[idx] != -1) return t[idx];

        int skip = solve(events, idx + 1, t);
        int take = events[idx][2];
        int j = bs(events, idx);  // O(log n)
        take += solve(events, j, t);

        return t[idx] = max(take, skip);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> events;

        for(int i = 0; i < n; i++){
            events.push_back({startTime[i], endTime[i], profit[i]});
        }
        vector<int> t(n+1, -1);
        sort(events.begin(), events.end());  // O(n log n)

        return solve(events, 0, t);
    }
};