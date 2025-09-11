class Solution {
  public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        int rsum = 0;
        int maxSum = 0;
        int rIndex = cardPoints.size() - 1;
        
        for(int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }
        
        maxSum = lsum;
        
        for(int i = k - 1; i >= 0; i--) {
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[rIndex];
            rIndex = rIndex - 1;
            maxSum = max(maxSum, lsum + rsum);
        }
        
        return maxSum;
    }
};
