// Company Tags: Accenture, Accolite, Adobe, Agoda, Airbnb, Akuna Capital, Amazon, American Express, Apple, Barclays, BlackRock, Bloomberg, Booking.com, Cisco, Citadel, Cognizant, DE Shaw, Disney, Docusign, EPAM Systems, Expedia, Epic Systems, eBay, Facebook (Meta), Goldman Sachs, Google, Huawei, IBM, Infosys, Intel, Intuit, J.P. Morgan, LinkedIn, Meta, Microsoft, Morgan Stanley, Netflix, Nvidia, Ozon, PayPal, Paytm, Qualcomm, Roblox, SAP, Salesforce, Samsung, ServiceNow, Siemens, Spotify, Swiggy, TCS, Tesla, TikTok, Tinkoff, Turing, Uber, Visa, Walmart Labs, Wipro, X, Yahoo, Yandex, Zeta, Zenefits, Zoho

// T.C: O(n)
// S.C: O(n)
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();

        for(int i = 0; i < n; i++){
            char ch = s[i];
        
            if(ch == ')' && !st.empty() && st.top() == '(') {
                st.pop();
                continue;
            }
            if(ch == '}' && !st.empty() && st.top() == '{') {
                st.pop();
                continue;
            }
            if(ch == ']' && !st.empty() && st.top() == '[') {
                st.pop();
                continue;
            }
            
            st.push(ch);

        }

        return st.empty();
    }
};