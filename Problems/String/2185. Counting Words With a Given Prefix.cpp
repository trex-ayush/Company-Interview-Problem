/*
    Problem Name: Leetcode 2185. Counting Words With a Given Prefix
    https://leetcode.com/problems/counting-words-with-a-given-prefix/description/
    Company : 
*/

/*
    Approach 1 
    Time Complexity : O(n*m) where n = the number of words in words and m = the length of the prefix string pref
    Space Complexity : O(m)
*/
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(auto& word : words){
            string p = word.substr(0,pref.length());
            if(p == pref) count++;
        }
        return count;
    }
};

/*
    Approach 2 - Teies
    Time Complexity : 
    Space Complexity :
*/

// will upadte