class Solution {
  public:
    int romanToDecimal(string &s) {
        unordered_map<char, int> mpp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        }; 
        int sum = 0;
        
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            sum += mpp[ch];
            if(i > 0 && mpp[s[i-1]] < mpp[ch]) sum -= 2*mpp[s[i-1]];
        }
        
        return sum;
    }
};