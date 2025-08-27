// Company tags: Accenture, Arista Networks, Capgemini, Cisco, Goldman Sachs, Infosys, Intel, Morgan Stanley, Paytm, Salesforce, Snap, TCS, TikTok, Visa, Walmart Labs, Wayfair, Yandex, Yelp, Zoho
class Solution {
public:
    // Time Complexity  : O(n)
    // Space Complexity : O(l), where l is the maximum length of a word
    string reverseWords(string s) {
        int n = s.length();
        reverse(s.begin(), s.end());
        
        string res = "";
        
        for(int j = 0; j < n; j++){
            if(s[j] == ' '){
                continue;
            }
            string temp = "";
            while(j < n && s[j] != ' '){
                temp = s[j] + temp;
                j++;
            }
            if (!res.empty()) res += " ";
            res += temp;
        }
        return res;
    }
};