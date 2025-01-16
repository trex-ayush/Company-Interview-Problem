/*
    Problem Name: Leetcode 3355. Zero Array Transformation I
    https://leetcode.com/problems/zero-array-transformation-i/description/
    Company :  
*/

/*
    Time Complexity : O(n + q)
    Space Complexity : O(n)
*/
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> vec(n+1 , 0);
        for(auto& q : queries){
            int st = q[0];
            int en = q[1];
            vec[st] = vec[st] + 1;
            vec[en + 1] = vec[en + 1] - 1;
        }
        for(int i = 0; i < n; i++){
            if(i != 0){
                vec[i] = vec[i - 1] + vec[i];
            }
            if(vec[i] < nums[i]) return false;
        }
        return true;
    }
};