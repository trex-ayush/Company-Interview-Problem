/*
    Problem Name: Leetcode 3223. Minimum Length of String After Operations
    https://leetcode.com/problems/minimum-length-of-string-after-operations/description/
    Company : IBM - 2
    Tags: Hashing 
*/

/*
    Time Complexity : O(n)
    Space Complexity : O(26) = O(1)
*/
    class Solution {
    public:
        int minimumLength(string s) {
            int n = s.length();
            vector<int>freq(26,0);

            for(int i = 0; i < n; i++){
                freq[s[i] - 'a']++;
            }
            
            int count = 0;
            for(int i = 0; i < 26; i++){
                if(freq[i] == 0) continue; 
                else if(freq[i] % 2 == 0){
                    count += 2;
                }else{
                    count += 1;
                }
            }
            return count;
        }
    };