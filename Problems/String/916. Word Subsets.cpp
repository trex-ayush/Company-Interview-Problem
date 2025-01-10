/*
    Problem Name: Leetcode 916. Word Subsets
    https://leetcode.com/problems/word-subsets/description/
    Company : 
*/

/*
    Approach 1 
    Time Complexity : O(n* len1 + m* len2)
    Space Complexity : O(1)
*/
class Solution {
private:
    bool subset(vector<int>& freq2, vector<int>& temp){
        for(int i = 0; i < 26; i++){
            if(temp[i] < freq2[i]) return false;
        }
        return true;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int>freq2(26,0);  // O(26)

        for(auto& word : words2){  // O(n)
            vector<int> temp(26,0);  // O(26)
            for(auto& ch : word){   // O(len1)
                temp[ch - 'a']++;
                freq2[ch - 'a'] = max(freq2[ch - 'a'] , temp[ch - 'a']);
            }
        }
        for(auto& word : words1){ // O(m)
            vector<int> temp(26,0); 
            for(auto& ch : word){  // O(len2)
                temp[ch - 'a']++;
            }
            if(subset(freq2 , temp)){  // O(1)
                ans.push_back(word);
            }
        }
        return ans;
    }
};