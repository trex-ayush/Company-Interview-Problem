1class Solution {
2public:
3    // T.C: O(n)
4    // S.C: O(1)
5    int minimumDeletions(string s) {
6        int n = s.size();
7        int cntOfB = 0;
8        int cnt = 0;
9
10        for(auto& ch : s){
11            if(ch == 'b'){
12                cntOfB++;
13            }else {
14                if(cntOfB > 0){
15                    cntOfB--;
16                    cnt++;
17                }
18            }
19        }
20
21        return cnt;
22    }
23};