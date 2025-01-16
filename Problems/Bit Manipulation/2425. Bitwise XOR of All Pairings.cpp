/*
    Problem Name: Leetcode 2425. Bitwise XOR of All Pairings
    https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/
    Company :  
*/

/*
    Approach 1 
    Time Complexity : O(n+m)
    Space Complexity : O(n+m)
*/
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<long,long> mpp;

        for(auto& num : nums1){
            mpp[num] += m;
        }
        for(auto& num : nums2){
            mpp[num] += n;
        }
        int count = 0;
        for(auto& mp : mpp){
            if(mp.second % 2 != 0){
                count ^= mp.first;
            }
        }
        return count;
    }
};

/*
    Approach 2
    Time Complexity : O(n+m)
    Space Complexity : O(1)
*/

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int count = 0;

        if(n % 2 != 0){
            for(auto& num : nums2){
                count ^= num;
            }
        }
        if(m % 2 != 0){
            for(auto& num : nums1){
                count ^= num;
            }
        }

        return count;
    }
};
