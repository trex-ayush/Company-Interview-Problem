class Solution {
  public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men.size();
    
        vector<int> womanPartner(n, -1); // woman -> man
        vector<int> manPartner(n, -1);   // man -> woman
        vector<int> nextProposal(n, 0);  // next woman index for each man
        
        // rank[w][m] = preference rank of man m for woman w
        vector<vector<int>> rank(n, vector<int>(n));
        
        for(int w = 0; w < n; w++) {
            for(int i = 0; i < n; i++) {
                rank[w][women[w][i]] = i;
            }
        }
        
        queue<int> freeMen;
        for(int i = 0; i < n; i++) {
            freeMen.push(i);
        }
        
        while(!freeMen.empty()) {
            int man = freeMen.front();
            freeMen.pop();
            
            int woman = men[man][nextProposal[man]];
            nextProposal[man]++;
            
            if(womanPartner[woman] == -1) {
                womanPartner[woman] = man;
                manPartner[man] = woman;
            }else {
                int otherMan = womanPartner[woman];
                
                if(rank[woman][man] < rank[woman][otherMan]) {
                   
                    womanPartner[woman] = man;
                    manPartner[man] = woman;
                    
                    freeMen.push(otherMan);
                }
                else {
                   
                    freeMen.push(man);
                }
            }
        }
        
        return manPartner;
    }
};