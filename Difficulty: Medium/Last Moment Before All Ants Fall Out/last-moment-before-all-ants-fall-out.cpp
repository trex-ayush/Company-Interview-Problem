class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for(auto& a : left) ans = max(ans,a);
        for(auto& a : right) ans = max(ans,n-a);
        return ans;
    }
};
