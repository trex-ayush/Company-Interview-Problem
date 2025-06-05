class Solution {
public:
    char dfs(unordered_map<char,vector<char>>& adj, char& ch, vector<bool>& visited){
        visited[ch-'a'] = true;
        char minChar = ch;

        for(auto& v : adj[ch]){
            if(!visited[v-'a']){
                minChar = min(minChar, dfs(adj,v,visited));
            }
        }
        return minChar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        int m = baseStr.length();

        unordered_map<char,vector<char>> adj;

        for(int i = 0; i < n; i++){
            char ch1 = s1[i];
            char ch2 = s2[i];

            adj[ch1].push_back(ch2);
            adj[ch2].push_back(ch1);
        }
        string ans;

        for(int i = 0; i < m; i++){
            char ch = baseStr[i];
            vector<bool> visited(26,false);
            char minChar = dfs(adj, ch, visited);

            ans.push_back(minChar);
        }
        return ans;
    }
};