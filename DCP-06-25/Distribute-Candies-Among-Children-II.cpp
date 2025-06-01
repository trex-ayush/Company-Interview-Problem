// Company Tags: Rubrik, Amazon
class Solution {
public:
    // T.C : O(n)
    // S.C : O(1)
    long long distributeCandies(int n, int limit) {
        
        // child 1
        int minCh1 = max(0, n-2*limit); // handle negative
        int maxCh1 = min(n, limit); 

        long long count = 0;

        for(int i = minCh1; i <= maxCh1; i++){
            // distribution between child2 & child3
            int N = n - i;
            int minCh2 = max(0, N-limit);
            int maxCh2 = min(N, limit);

            count += (maxCh2 - minCh2 + 1);
        }
        return count;
    }
};