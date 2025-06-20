// Company tags: Palantir Technologies, META
// T.C: O(nlogn)
// S.C: O(n)
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;

        for (auto& t : timePoints) {
            int hrs = stoi(t.substr(0, 2));
            int min = stoi(t.substr(3, 2));
            time.push_back(hrs * 60 + min);
        }

        sort(time.begin(), time.end());

        int mini = INT_MAX;
        for (int i = 0; i < time.size() - 1; ++i) {
            mini = min(mini, time[i + 1] - time[i]);
        }

        // Circular difference: compare last and first in the 24-hour cycle
        int circularDiff = 1440 - time.back() + time.front();
        mini = min(mini, circularDiff);

        return mini;
    }
};
