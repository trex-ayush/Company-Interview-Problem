class Solution {
  public:
    int minParentheses(string& s) {
        int n =  s.size();
        int open = 0;
        int close = 0;
        
        int res = 0;
        
        for(int i = 0; i < n; i++){
            if(s[i] == '(') open++;
            else close++;
            if(open == close){
                open = 0;
                close = 0;
            }
            if(close > open) {
                res++;
                close = 0;
            }
        }
        return res + (open - close);
    }
};