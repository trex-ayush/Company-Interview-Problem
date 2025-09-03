class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        int n = s.size();
        int open = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                open++;
            }else if(s[i] == ')'){
                if(open > 0) open--;
                else count += 1;
            }
        }
        count += open;
        return count;
    }
};