class Solution {
public:
    string findOrder(vector<string> &words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> inDegree;
        unordered_set<char> allChars;
        
        // Step 1: Initialize graph
        for (string &word : words) {
            for (char c : word) {
                allChars.insert(c);
                if (!inDegree.count(c)) inDegree[c] = 0;
            }
        }
        
        // Step 2: Build graph (edges based on first differing characters)
        for (int i = 0; i < words.size() - 1; ++i) {
            string &w1 = words[i];
            string &w2 = words[i + 1];
            int minLen = min(w1.size(), w2.size());
            bool foundDifference = false;
            
            for (int j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]);
                    inDegree[w2[j]]++;
                    foundDifference = true;
                    break;
                }
            }
            
            // Invalid case: prefix violation
            if (!foundDifference && w1.size() > w2.size()) {
                return "";
            }
        }
        
        // Step 3: Topological Sort (Kahn's Algorithm)
        queue<char> q;
        for (char c : allChars) {
            if (inDegree[c] == 0) q.push(c);
        }
        
        string result;
        while (!q.empty()) {
            char curr = q.front(); 
            q.pop();
            result += curr;
            
            for (char neighbor : adj[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // If result does not include all characters, cycle exists
        if (result.size() != allChars.size()) return "";
        
        return result;
    }
};
