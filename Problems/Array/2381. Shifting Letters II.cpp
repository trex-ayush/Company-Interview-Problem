/*
    Problem Name: 2381. Shifting Letters II
    https://leetcode.com/problems/shifting-letters-ii/description/
    Company : 
*/

/*
    Approach 1 (Brute force)
    Time Complexity : O(n * q)
    Space Complexity : O(1)
*/
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        for(auto& shift : shifts){
            int start     = shift[0];
            int end       = shift[1];
            int direction = shift[2];

            if(direction == 1){
                for(int st = start; st <= end; st++){
                    s[st] = (s[st] == 'z'  ? 'a' : s[st] + 1 );
                }
            }else{
                for(int st = start; st <= end; st++){
                    s[st] = (s[st] == 'a'  ? 'z' : s[st] - 1 );
                }
            }
        }
        return s;
    }
};

/*
    Approach 2 - Difference Array
    Time Complexity : O(n + n + q) = O(n + q)
    Space Complexity : O(n)
*/
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n,0);

        for(auto& shift : shifts){
            int start     = shift[0];
            int end       = shift[1];
            int direction = shift[2];

            int x;
            if(direction == 0){
                x = -1;
            }else{
                x = 1;
            }
            diff[start] += x;
            if(end + 1 < n) diff[end + 1] -= x;
        }

        for(int i = 1; i < n; i++){
            diff[i] = diff[i] + diff[i-1];
        }
        
        for(int i = 0; i < n; i++){
            int shift = diff[i] % 26;   // to wrap around z to a
            if(shift < 0) shift += 26;  // to wrap around a to z
            
            s[i] = ((s[i] - 'a') + shift) % 26 + 'a' ;
        }
        return s;
    }
};