/*
    Problem Name: Geeksforgeeks and Leetcode 3. Longest Substring Without Repeating Characters
    https://www.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/
    https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
    Company: Amazon (1+ year ago), Microsoft (1+ year ago), Housing.com (1+ year ago), Adobe (1+ year ago)
    Tags: Hashing, Sliding Window
*/

/*
    Time Complexity : O(n^2)
    Space Complexity : O(1)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> lastIndex(26, -1); 
        int i = 0; 
        int maxLen = 0;
        
        int j = 0;
        while (j < n) {
            char currentChar = s[j];
            int charIndex = currentChar - 'a'; 
            
            if (lastIndex[charIndex] >= i) {
                i = lastIndex[charIndex] + 1;
            }
            
            lastIndex[charIndex] = j;
            
            maxLen = max(maxLen, j - i + 1);
            
            j++;
        }
        return maxLen;
    }
};