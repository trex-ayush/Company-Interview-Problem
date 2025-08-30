class Solution {
public:
    static bool comp(pair<char,int>& a, pair<char,int>& b) {
        return a.second > b.second;
    }

    string frequencySort(string &s) {
        unordered_map<char,int> count;
        
        for(char ch : s) count[ch]++;
        
        vector<pair<char,int>> freq(count.begin(), count.end());
        
        sort(freq.begin(), freq.end(), comp);
        
        string res = "";
        for(auto &p : freq) {
            res += string(p.second, p.first);
        }
        
        return res;
    }
};