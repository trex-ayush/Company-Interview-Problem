class Solution {
  public:
    int countConsec(int n) {
        if(n == 2) return 1;
        
        int firstNum = 0;
        int secondNum = 1;
        int thirdNum;
        int result = 1;
        
        for(int i = 3; i <= n; i++){
            thirdNum = firstNum + secondNum;
            result = result * 2 + thirdNum;
            firstNum = secondNum;
            secondNum = thirdNum;
        }
        
        return result;
    }
};