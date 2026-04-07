1// Company tags: Block
2class Robot {
3public:
4    int w;
5    int h;
6    string currDir;
7    int x;
8    int y; 
9
10    Robot(int width, int height) {
11        w = width;
12        h = height;
13        currDir = "East";
14        x = 0;
15        y = 0;
16    }
17    
18    void step(int num) { // O(num % perimeter - 4) = O(num % perimeter) = O(perimeter) = O(w + h)
19        // Robot rectangle ke boundary pe ghoom raha hai. 
20        // Woh same path repeat karta hai.
21        int cycle = 2 * (w + h) - 4;
22
23        num %= cycle;
24
25        // If num % cycle == 0, treat it as a full cycle
26        if (num == 0) {
27            num = cycle;
28        }
29
30        for(int i = 0; i < num; i++){
31            if(currDir == "East"){
32                if(x + 1 < w){
33                    x++;
34                } else {
35                    currDir = "North";
36                    y++;
37                }
38            } else if(currDir == "North"){
39                if(y + 1 < h){
40                    y++;
41                } else {
42                    currDir = "West";
43                    x--;
44                }
45            } else if(currDir == "West"){
46                if(x - 1 >= 0){
47                    x--;
48                } else {
49                    currDir = "South";
50                    y--;
51                }
52            }
53            else { // South
54                if(y - 1 >= 0){
55                    y--;
56                } else {
57                    currDir = "East";
58                    x++;
59                }
60            }
61        }
62    }
63    
64    vector<int> getPos() { // O(1)
65        return {x, y};
66    }
67    
68    string getDir() { // O(1)
69        return currDir;
70    }
71};