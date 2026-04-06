1// Company tags: Phonepe
2class Solution {
3public:
4    // T.C: O(klogk + nlog(sum of commands))
5    // S.C: O(k)
6    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
7        set<pair<int,int>> st;
8
9        for(auto& obstacle : obstacles) { // O(k)
10            int x = obstacle[0];
11            int y = obstacle[1];
12            st.insert({x, y}); // O(log k)
13        }
14
15        int x = 0;
16        int y = 0;
17        int maxDist = 0;
18
19        char currentDirection = 'N';
20
21        for(auto& command : commands) {  // O(n)
22            if(command == -1) {
23                // turn right
24                if (currentDirection == 'N') currentDirection = 'E';
25                else if (currentDirection == 'E') currentDirection = 'S';
26                else if (currentDirection == 'S') currentDirection = 'W';
27                else currentDirection = 'N';
28            }else if(command == -2) {
29                // turn left
30                if (currentDirection == 'N') currentDirection = 'W';
31                else if (currentDirection == 'W') currentDirection = 'S';
32                else if (currentDirection == 'S') currentDirection = 'E';
33                else currentDirection = 'N';
34            }else {
35                for(int i = 0; i < command; i++) { // O(sum of commands)
36                    int newX = x;
37                    int newY = y;
38                    if(currentDirection == 'N') {
39                        newY++;
40                    }else if(currentDirection == 'S') {
41                        newY--;
42                    }else if(currentDirection == 'E') {
43                        newX++;
44                    }else {
45                        newX--;
46                    }
47                    if(st.count({newX, newY})) break; // O(log k)
48
49                    x = newX;
50                    y = newY;
51                    maxDist = max(maxDist, x*x + y*y);
52                }
53            }
54        }
55
56        return maxDist;
57    }
58};