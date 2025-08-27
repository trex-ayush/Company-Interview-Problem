class Solution {
  public:
    string maxOdd(string s) {
        int n = s.length();
        
        for(int i = n - 1; i >= 0; i--){
            char ch = s[i];
            int num = ch - '0';
            
            if(num % 2 != 0){
                return s.substr(0, i+1);
            }
        }
        return "";
    }
};