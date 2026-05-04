class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        if(n == 0) return true;
        int x = log2(n) + 1;
        
        int i = 0, j = x-1;
        
        while(i < j){
            int left  = (n >> i) & 1;
            int right = (n >> j) & 1;

            if(left != right) return false;

            i++;
            j--;
        }

        return true;
    }
};