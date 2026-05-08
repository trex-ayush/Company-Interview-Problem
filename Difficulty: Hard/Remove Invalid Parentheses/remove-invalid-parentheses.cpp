/*
Approach:
1. Count minimum invalid '(' and ')' brackets to remove.
2. Use backtracking:
   - Remove current bracket if possible.
   - Or keep the current character.
3. At the end, check validity and store unique answers.
4. Return all valid strings in sorted order.

Time Complexity: Exponential
Space Complexity: O(N)
*/

class Solution {
public:
    unordered_set<string> mp;
    bool isvalid(string &s) {
        int cnt = 0;
        
        for(char ch : s) {
            if(ch == '(') cnt++;
            else if(ch == ')') {
                if(cnt == 0) return false;
                cnt--;
            }
        }
        
        return cnt == 0;
    }

    void fun(int i, string &s, string temp, int c1, int c2) {
        if(i >= s.size()) {
            if(c1 > 0 || c2 > 0) return;
            if(isvalid(temp)) mp.insert(temp);
            return;
        }
        
        if(c1 && s[i] == '(') fun(i + 1, s, temp, c1 - 1, c2);
        if(c2 && s[i] == ')') fun(i + 1, s, temp, c1, c2 - 1);
        
        fun(i + 1, s, temp + s[i], c1, c2);
    }

    vector<string> validParenthesis(string &s) {
        if(isvalid(s)) return {s};
        
        int c1 = 0, c2 = 0;
        
        for(char ch : s) {
            if(ch == '(') c1++;
            else if(ch == ')') {
                if(c1 > 0) c1--;
                else c2++;
            }
        }
        
        fun(0, s, "", c1, c2);
        
        vector<string> ans(mp.begin(), mp.end());
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};