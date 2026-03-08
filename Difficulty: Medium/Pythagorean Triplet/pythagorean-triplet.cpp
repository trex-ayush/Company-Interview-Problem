class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int>st(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int a = arr[i];
                int b = arr[j];
                
                int sq = (a * a) + (b * b);
                int c = sqrt(sq);
                if(c*c == sq && st.find(c) != st.end()) return true;
            }
        }
        return false;
    }
};