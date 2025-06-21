// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        if (arr.empty()) return "";
        
        for (int i = 0; i < arr[0].size(); i++) {
            char ch = arr[0][i];
            
            for (int j = 1; j < arr.size(); ++j) {
                if (i >= arr[j].size() || arr[j][i] != ch) {
                    return arr[0].substr(0, i);
                }
            }
        }
        return arr[0];
    }
};