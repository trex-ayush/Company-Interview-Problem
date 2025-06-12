class Solution {
public:
    int reverse(int n) {
        long long num = 0;
        
        while(n){
            int digit = n % 10;
            num = num * 10 + digit;
            n /= 10;
        }
        if(num > INT_MAX || num < INT_MIN) return 0;
        return (int)num;
    }
};