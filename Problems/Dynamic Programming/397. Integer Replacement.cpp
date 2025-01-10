/*
    Problem Name: Leetcode 397. Integer Replacement
    https://leetcode.com/problems/integer-replacement/description/
    Company : 
*/

/*
    Approach 1 
    Time Complexity : O(logn)
    Space Complexity : O(n)
*/
class Solution {
private:
    unordered_map<long long, int> memo;

    int solve(long long n) {
        if (n == 1) return 0;
        if (memo.find(n) != memo.end()) return memo[n];
        
        int even = INT_MAX;
        int odd_minus = INT_MAX;
        int odd_plus = INT_MAX;

        if (n % 2 == 0) {
            even = 1 + solve(n / 2);
        } else {
            // Handle the case for n-1 and n+1 without overflow issues
            odd_minus = 1 + solve(n - 1);
            // Only compute n + 1 if it's within a valid range
            if (n < LLONG_MAX) {
                odd_plus = 1 + solve(n + 1);
            }
        }

        memo[n] = min(even,min(odd_minus, odd_plus));
        return memo[n];
    }

public:
    int integerReplacement(int n) {
        return solve(n);
    }
};