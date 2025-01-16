/*
    Problem Name: Leetcode 2657. Find the Prefix Common Array of Two Arrays
    https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/
    Company : 
*/

/*
    Approach 1
    Time Complexity : O(n^2)
    Space Complexity : O(n)
*/
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n, 0);
        unordered_set<int> seenA, seenB;

        for (int i = 0; i < n; i++) {
            seenA.insert(A[i]);
            seenB.insert(B[i]);
            int commonCount = 0;
            for (auto& num : seenA) {
                if(seenB.find(num) != seenB.end()) {
                    commonCount++;
                }
            }
            ans[i] = commonCount;
        }
        return ans;
    }
};

/*
    Approach 2
    Time Complexity : O(n)
    Space Complexity : O(n)
*/
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n, 0);
        unordered_map<int,int> seen;

        int commonCount = 0;
        
        for (int i = 0; i < n; i++) {
            seen[A[i]]++;
            if(seen[A[i]] == 2) commonCount++;
            seen[B[i]]++;
            if(seen[B[i]] == 2) commonCount++;
            ans[i] = commonCount;
        }
        return ans;
    }
};
