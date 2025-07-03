class Solution {
public:
    char solve(string& str, int& k){
        if(str.size() >= k) return str[k-1];

        string temp = "";

        for(int i = 0; i < str.size(); i++){
            temp += (str[i]+1);
        }
        if(str.size() >= k) return str[k-1];
        str += temp;
        return solve(str, k);
    }
    char kthCharacter(int k) {
        string str = "a";
        return solve(str, k);
    }
};