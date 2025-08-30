class Solution {
public:
    int maxDepth(string s) {
        int count  = 0;
        int maxLen = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                count++;
            }else if(s[i] == ')'){
                maxLen = max(maxLen, count);
                count--;
            }
        }
        return maxLen;
    }
};