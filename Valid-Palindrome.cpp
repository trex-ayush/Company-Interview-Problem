// Company tags: Accenture, American Express, Capgemini, Cisco, EPAM Systems, Infosys, PayPal, ServiceNow, SAP, Spotify, TikTok, Turing, Wipro, Wayfair, Yandex, Zenefits

class Solution {
public:
    // Time Complexity  : O(n)
    // Space Complexity : O(1)
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;

        while(i <= j){
            if (!isalnum(s[i])) i++;
            else if (!isalnum(s[j])) j--;
            else {
                if (tolower(s[i]) != tolower(s[j])) return false;
                i++;
                j--;
            }
        }

        return true;
    }
};