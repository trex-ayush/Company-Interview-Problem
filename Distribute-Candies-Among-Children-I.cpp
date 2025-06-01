// Company Tags: Rubrik
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long count = 0;

        for (int a = 0; a <= min(n, limit); a++) {
            for (int b = 0; b <= min(n - a, limit); b++) {
                int c = n - a - b;
                if (0 <= c && c <= limit) {
                    count++;
                }
            }
        }
        
        return count;
    }
};