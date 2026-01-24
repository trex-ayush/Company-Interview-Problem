class Solution {
  public:
    int solve(int n,int k){
        if(n == 1) return 0;
        return (solve(n - 1, k) + k) % n;
    }
  
    int josephus(int n, int k) {
        return solve(n,k)+1;
    }
};