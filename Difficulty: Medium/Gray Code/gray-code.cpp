class Solution {
public:
    vector<string> graycode(int n) {
        if (n == 1) {
            vector<string> result;
            result.push_back("0");
            result.push_back("1");
            return result;
        }
        
        vector<string> previous = graycode(n - 1);
        vector<string> result;
        
        for (int i = 0; i < previous.size(); i++) {
            result.push_back("0" + previous[i]);
        }
        
        for (int i = previous.size() - 1; i >= 0; i--) {
            result.push_back("1" + previous[i]);
        }
        
        return result;
    }
};