class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.length();

        for(int i = 0; i < n; i += k){
            ans.push_back(s.substr(i, k));
        }

        if(ans.back().length() != k){
            while(ans.back().length() != k){
                ans.back() += fill;
            }
        }

        return ans;
    }
};