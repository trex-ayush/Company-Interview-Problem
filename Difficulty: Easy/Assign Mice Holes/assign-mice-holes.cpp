class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        int n = mices.size();
        int maxi = INT_MIN;
        
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        
        
        for(int i = 0; i < n; i++){
            maxi = max(maxi, abs(mices[i] - holes[i]));
        }
        
        return maxi;
    }
};
