/*
Problem Name: 2559. Count Vowel Strings in Ranges
https://leetcode.com/problems/count-vowel-strings-in-ranges/description/
Company : Google , Bloomberg , Amazon , Adobe , Yahoo
*/


/*
    Approach 1 - Brute Force
    Time Complexity : O(n * q)
    Space Complexity : O(1)
*/
class Solution {
public:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto& q : queries){
            int st = q[0];
            int en = q[1];
            int count = 0;
            for(int i = st ; i <= en; i++){
                string word = words[i];
                char st = word[0];
                char en = word[word.length() - 1];
                if(isVowel(st) && isVowel(en)) count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};

/*
    Approach 2 - Optimal 
    Time Complexity : O(n + q)
    Space Complexity : O(n + q)
*/
class Solution {
public:
    bool isVowel(char& ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int q = queries.size();
        int n = words.size();
        vector<int> ans(q);
        vector<int> cumm_sum(n);
        int sum = 0;

        for(int i = 0; i < n; i++){
            string word = words[i];
            if( isVowel(word[0]) && isVowel(word.back()) ) {
                sum++;
            }
            cumm_sum[i] = sum; 
        }

        for(int i = 0; i < q; i++){
            int st = queries[i][0];
            int en = queries[i][1];

            ans[i] = cumm_sum[en] - ((st > 0) ? cumm_sum[st-1] : 0);
        }

        return ans;
    }
};