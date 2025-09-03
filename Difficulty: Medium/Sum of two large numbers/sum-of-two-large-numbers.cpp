// User function template for C++
class Solution {
  public:
    string findSum(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        
        if(m > n) return findSum(s2, s1);
        
        int i = n-1;
        int j = m-1;
        int carry = 0;
        string res = "";
        
        while(j >= 0){
            int num1 = s1[i] - '0';
            int num2 = s2[j] - '0';
            
            int sum = num1 + num2 + carry;
            int digit = sum % 10;
            carry = sum/10;
            
            res += to_string(digit);
            i--;
            j--;
        }
        while(i >= 0){
            int num1 = s1[i] - '0';
            
            int sum = num1 + carry;
            int digit = sum % 10;
            carry = sum/10;
            
            res += to_string(digit);
            i--;
        }
        while(carry){
            int digit = carry % 10;
            carry = carry/10;
            res += to_string(digit);
        }
        reverse(res.begin(), res.end());
        int start = 0;
        while (start < res.size() && res[start] == '0') {
            start++;
        }
        if (start == res.size()) return "0";
        return res.substr(start);
    }
};