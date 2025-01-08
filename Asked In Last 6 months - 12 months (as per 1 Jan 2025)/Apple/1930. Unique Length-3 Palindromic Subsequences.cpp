/*
    Problem Name: 1930. Unique Length-3 Palindromic Subsequences
    https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
    Company : Google - 3, Adobe - 3, Meta - 2, Amazon - 2, Apple - 2, Uber -2
*/

/*
    Time Complexity : O(n + 26) = O(n)
    Space Complexity : O(26) = O(1)
*/
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<char> st; // max 26 letter O(26)
        for(char& ch : s){
            st.insert(ch);
        }
        int ans = 0;
        for(auto& ch : st){   // O(26)
            int startingIdx = -1;
            int endingIdx   = -1;
            
            for(int i = 0; i < n; i++){   // O(n)
                if(s[i] == ch){
                    if(startingIdx == -1){
                        startingIdx = i;
                    }
                    endingIdx = i;
                }
            }
            unordered_set<char> stt;
            for(int k = startingIdx + 1; k < endingIdx; k++){ // O(n)
                stt.insert(s[k]);
            }
            ans += stt.size();
        }
        return ans;
    }
};