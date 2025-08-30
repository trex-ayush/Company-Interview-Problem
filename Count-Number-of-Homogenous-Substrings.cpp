class Solution {
public:
    const int mod = 1e9+7;
    int countHomogenous(string s) {
        int n = s.size();

        long long count = 1;
        long long res = 0;
        for(int i = 1; i < n; i++){
            if(s[i] == s[i-1]){
                count++;
            }else{
                res = (res + (count * (count + 1) / 2) % mod);
                count = 1;
            }
        }
        // last 
        res = (res + (count * (count + 1) / 2) % mod);
        return res % mod;
    }
};