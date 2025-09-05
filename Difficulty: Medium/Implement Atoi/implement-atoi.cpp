class Solution {
public:
    bool isValid(char ch) {
        return ch >= '0' && ch <= '9';
    }

    void solve(string& s, int idx, int& num, bool& isNeg, bool& started) {
        if (idx >= s.size()) return;
        char ch = s[idx];
        
        if (!started && ch == ' ') {
            solve(s, idx + 1, num, isNeg, started);
            return;
        }
        if (!started && ch == '-') {
            isNeg = true;
            started = true;
            solve(s, idx + 1, num, isNeg, started);
            return;
        }
        if (!started && ch == '+') {
            started = true;
            solve(s, idx + 1, num, isNeg, started);
            return;
        }
        if (isValid(ch)) {
            started = true;
            int digit = ch - '0';
            
            // Overflow checks
            if (!isNeg && (num > (INT_MAX - digit) / 10)) {
                num = INT_MAX;
                return;
            }
            if (isNeg && (num > (-(INT_MIN + digit)) / 10)) {
                num = INT_MIN;
                return;
            }
            
            num = num * 10 + digit;
            solve(s, idx + 1, num, isNeg, started);
            return;
        }
        return;
    }

    int myAtoi(string& s) {
        int num = 0;
        bool isNeg = false;
        bool started = false;
        solve(s, 0, num, isNeg, started);
        return isNeg ? -num : num;
    }
};
