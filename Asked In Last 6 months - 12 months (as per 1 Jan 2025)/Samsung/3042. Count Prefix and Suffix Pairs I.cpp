/*
    3042. Count Prefix and Suffix Pairs I
    https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/
    Company : Samsung-10 Autodesk-4 FICO-10 Uber-2
*/

/*
    Approach 1 
    Time Complexity : O(n^2 * k) k is the length of the longest string in the vector
    Space Complexity : O(n)
*/
class Solution {
private:
    bool isPrefixAndSuffix(string& str1,string& str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        if(len1 > len2) return false;
        
        bool isPrefix = str2.substr(0, len1) == str1;
        bool isSuffix = str2.substr(len2 - len1, len1) == str1;
        
        return isPrefix && isSuffix;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if (isPrefixAndSuffix(words[i], words[j])){
                    count++;
                    continue;
                }
            }
        }

        return count;
    }
};