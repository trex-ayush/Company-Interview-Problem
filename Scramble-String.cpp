// Company tags: Media.net, Rubrik, Google, Apple, Amazon
class Solution {
  public:
    // Time Complexity  : O(n³)  => O(number of subproblems) × O(work per subproblem) = O(n²) × O(n) = O(n³)
    // Space Complexity : O(n²)

    unordered_map<string, bool> dp;
    bool solve(string s, string t){
        if(s == t) return true;
        if(s.empty()) return false;
        
        string key = s + "-" + t; 
        
        if(dp.find(key) != dp.end()) return dp[key];
        
        int n = s.size();
        for (int i = 1; i < n; i++) {
            bool noSwap = solve(s.substr(0, i), t.substr(n - i)) &&
                          solve(s.substr(i), t.substr(0, n - i));
            bool swap = solve(s.substr(0, i), t.substr(0, i)) &&
                          solve(s.substr(i), t.substr(i));
                         
            if (noSwap || swap) return dp[key] = true;
        }
        return dp[key] = false;
    }
    bool isScramble(string s, string t) {
        if(s.size() != t.size()) return false;
        
        return solve(s, t);
    }
};
