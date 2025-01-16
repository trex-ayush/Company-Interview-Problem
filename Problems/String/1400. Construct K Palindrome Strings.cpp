/*
    Problem Name: Leetcode 1400. Construct K Palindrome Strings
    https://leetcode.com/problems/construct-k-palindrome-strings/description/
    Company : 
    Tags: Hashing 
*/

/*
    Time Complexity : O(n)
    Space Complexity : O(26) = O(1)
*/
class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(n < k) return false;
        if(n == k) return true;

        vector<int> freq(26,0);
        for(auto& ch : s){
            freq[ch - 'a']++;
        }
        int oddFreqChar = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i]%2 != 0){
                oddFreqChar++;
            }
        }
        return oddFreqChar <= k;
    }
};