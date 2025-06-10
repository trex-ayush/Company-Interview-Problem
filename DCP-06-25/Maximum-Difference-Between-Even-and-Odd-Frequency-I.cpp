class Solution {
public:
    int maxDifference(string s) {
        int n = s.length();
        vector<int> vec(26,0);
        for(int i = 0; i < n; i++){
            vec[s[i] - 'a']++;
        }
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i = 0; i < 26; i++){
            if(vec[i] == 0) continue;
            
            if(vec[i] % 2 == 1){
                maxi = max(maxi,vec[i]);
            }else mini = min(mini,vec[i]);
        }
        return (maxi != INT_MIN && mini != INT_MAX) ? maxi - mini : 0;
    }
};