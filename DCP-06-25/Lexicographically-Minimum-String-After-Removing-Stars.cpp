class Solution {
public:
    // T.C: O(n)
    // S.C: O(n)
    typedef pair<char, int> P;
    struct comp{
        bool operator()(P& p1, P& p2){
            if(p1.first == p2.first) return p1.second < p2.second;
            return p1.first > p2.first;
        }
    };
    string clearStars(string s) {
        int n = s.length();
        priority_queue<P, vector<P>, comp> pq;

        for(int i = 0; i < n; i++){
            if(s[i] == '*') {
                auto top = pq.top();
                s[top.second] = '*';
                pq.pop();
            }
            else pq.push({s[i], i});
        }

        string ans = "";
        for(auto& ch : s){
            if(ch != '*') ans += ch;
        }

        return ans;
    }
};