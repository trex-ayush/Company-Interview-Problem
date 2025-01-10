/*
    Problem Name: Leetcode 551. Student Attendance Record I
    https://leetcode.com/problems/student-attendance-record-i/description/
    solution : https://leetcode.com/problems/student-attendance-record-i/solutions/6251083/beats-100-beginner-friendly-with-explanation
    Company : 
*/

/*
    Approach 1 
    Time Complexity : O(n)
    Space Complexity : O(1)
*/
class Solution {
public:
    bool checkRecord(string s) {
        int lateCount = 0;
        int absentCount = 0;

        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == 'A') {
                absentCount++;
                if(absentCount >= 2) return false;
            }
            if(s[i] == 'L') {
                lateCount++;
                if(lateCount == 3) return false;
            } else {
                lateCount = 0;
            }
        }
        return absentCount < 2 && lateCount <= 3;
    }
};