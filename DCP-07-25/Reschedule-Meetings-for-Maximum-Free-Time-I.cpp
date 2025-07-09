class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> free;

        free.push_back(startTime[0]);
        for(int i = 1; i < startTime.size(); i++){
            free.push_back(startTime[i] - endTime[i-1]);
        }
        free.push_back(eventTime - endTime[startTime.size()-1]);

        // sliding window
        int i = 0;
        int j = 0;
        int maxSum = 0;
        int sum = 0;

        int n = free.size();

        while(j < n){
            sum += free[j];

            while(i < n && j-i+1 > k+1){
                sum -= free[i];
                i++;
            }
            maxSum = max(maxSum, sum);
            j++;
        }

        return maxSum;
    }
};