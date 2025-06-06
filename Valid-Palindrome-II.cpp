// Company tags: eBays, Walmart Labs
class Solution {
public:
    // T.C: O(n)
    // S.C: O(1)
    bool check(string& s, int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }else {
                i++;
                j--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.length();

        int i = 0;
        int j = n-1;

        while(i < j){
            if(s[i] == s[j]){
                i++;
                j--;
            }else {
                return check(s,i+1,j) || check(s,i,j-1);
            }
        }
        return true;
    }
};