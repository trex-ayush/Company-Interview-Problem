class Solution {
  public:
    vector<int> asciirange(string& s) {
        int n = s.length();
        
        unordered_map<char,pair<int,int>> mpp;
        
        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(mpp.find(ch) != mpp.end()){
                mpp[ch].second = i;
            }else{
                mpp[ch] = {i,i};
            }
        }
        
        vector<int> prefixSum(n, 0);
        prefixSum[0] = s[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1]+s[i];
        }
        
        vector<int> result;
        unordered_set<char> seen;
        
        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(!seen.count(ch) && mpp[ch].first != mpp[ch].second){
                int totalSum = prefixSum[mpp[ch].second-1] - prefixSum[mpp[ch].first];
                if(totalSum) result.push_back(totalSum);
                seen.insert(ch);
            }
        }
        return result;
    }
};