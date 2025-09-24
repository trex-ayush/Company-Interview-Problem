class Solution {
  public:
    vector<string> generateBinary(int n) {
        vector<string> ans;
        queue<string> q;
        q.push("1");
        
        while (n--) {
            string current = q.front();
            q.pop();
            ans.push_back(current);
            q.push(current + "0");
            q.push(current + "1");
        }
        
        return ans;
    }
    
    

};