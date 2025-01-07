/*
    Problem Name: 1769. Minimum Number of Operations to Move All Balls to Each Box
    https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/
    Company : 
*/

/*
    Approach 1 
    Time Complexity : O(n^2)
    Space Complexity : O(1)
*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n,0);

        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                if(boxes[j] == '1'){
                    sum += abs(i - j);
                }
            }
            ans[i] = sum;
        }
        return ans;
    }
};