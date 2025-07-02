// Company Tags: Dropbox, Grammarly, Myntra, Oracle, ServiceNow, Snap, TikTok, X
class Solution {
public:
    // Time Complexity : O(2^n * n)
    // Space Complexity: O(n) (Excluding result)
    void solve(string& s, unordered_set<string>& set, vector<string>& result, string& temp, int idx){
        if(idx >= s.size()){
            result.push_back(temp);
            return;
        }

        for(int L = 1; idx + L <= s.size(); L++){
            string str = s.substr(idx, L);
            if(set.find(str) != set.end()){
                string origSentence = temp;
                if (!temp.empty()) temp += " ";
                temp += str;

                solve(s, set, result, temp, idx + L);

                temp = origSentence;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;

        for(auto& word : wordDict){
            set.insert(word);
        }

        vector<string> result;
        string temp = "";
        solve(s, set, result, temp, 0);

        return result;
    }
};