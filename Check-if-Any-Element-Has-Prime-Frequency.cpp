class Solution {
public:
    bool isPrime(int n){
        if(n == 1) return false;
        if(n == 2 || n == 3) return true;

        if(n % 2 == 0) return false;

        for(int i = 3; i * i <= n; i += 2){
            if(n % i == 0) return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> mpp;

        for(auto& num : nums) mpp[num]++;

        for(auto& mp : mpp){
            if(isPrime(mp.second)) return true;
        }
        return false;
    }
};