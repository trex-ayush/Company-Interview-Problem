class Solution {
public:
    // Time Complexity : O(n)
    // Space Complexity: O(1)
    int possibleStringCount(string word) {
        int n = word.size();
        int result = 1;
        
        for(int i = 0; i < n - 1; i++){
            if(word[i] == word[i+1]) result++;
        }
        
        return result;
    }
};