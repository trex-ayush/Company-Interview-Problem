// Company tags: Agoda, Citadel, Cruise, eBay, LinkedIn, Nutanix, PhonePe, Samsung, Snap, TikTok, Yelp
class Solution {
public:
    // Time Complexity: O(N * M * log N)
    // Space Complexity: O(N)
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        if(startWord == targetWord) return 0;
        
        set<string> st;
        for(auto& word : wordList) st.insert(word); // O(log n)
        
        if (st.find(targetWord) == st.end()) return 0;
        
        queue<string> q;
        q.push(startWord);
        st.erase(startWord);
        
        int level = 1;
        
        while(!q.empty()){
            int k = q.size();
            while(k--){
                string temp = q.front();
                q.pop();
                
                for(int i = 0; i < temp.size(); i++){
                    char originalChar = temp[i];
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        if(ch == originalChar) continue;
                        temp[i] = ch;
                        if(st.find(temp) != st.end()) {
                            if (temp == targetWord) return level + 1;
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                    temp[i] = originalChar;
                }
            }
            level++;
        }
        return 0;
    }
};