class Solution {
public:
    // T.C: O(n^2)
    // S.C: O(1) (excluding the space used by the answer string)
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        int n = word.size();
        int largestPossible = n - (numFriends - 1);

        string ans = "";

        for(int i = 0; i < n; i++){
            string str = word.substr(i,min(largestPossible, n-i));  //O(n)
            if(str > ans) ans = str;
        }   
        return ans;
    }
};