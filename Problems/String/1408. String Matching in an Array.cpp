/*
    Problem Name: 1408. String Matching in an Array
    https://leetcode.com/problems/string-matching-in-an-array/description/
    Company : 
*/

/*
    Approach 1 
    Time Complexity : O(n^2 + m)
    Space Complexity : O(1)
*/
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(words[j].find(words[i]) != string::npos) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};