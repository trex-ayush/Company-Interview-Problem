class Solution {
  public:
    bool divby13(string &s) {
        int remainder = 0;
        for (char c : s) {
            int digit = c - '0';
            remainder = (remainder * 10 + digit) % 13;
        }
        return remainder == 0;
    }
};