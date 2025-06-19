class Solution {
  public:
    // T.C: O(nlogn)
    // S.C: O(n)
    string caseSort(string& s) {
        string ans = "";
        string lower = "";  
        string uppar = "";
        
        for(auto& ch : s){
            if(islower(ch)){
                lower += ch;
            }else uppar += ch;
        }
        
        sort(lower.begin(), lower.end());
        sort(uppar.begin(), uppar.end());
        
        int i = 0;
        int j = 0;
        
        for(auto& ch : s){
            if(islower(ch)){
                ans += lower[i++];
            }else ans += uppar[j++]; 
        }
        return ans;
    }
};