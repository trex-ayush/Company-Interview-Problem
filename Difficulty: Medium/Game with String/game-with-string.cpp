class Solution {
  public:
    int minValue(string &s, int k) {
        vector<int> freq(26, 0);
        
        for(auto& ch : s) freq[ch - 'a']++;
        
        priority_queue<pair<int,int>> pq;
        
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                pq.push({freq[i], i + 'a'});
            }
        }
        
        int count = 0;
        while(!pq.empty() && count < k){
            pair<int, int> top = pq.top();
            pq.pop();
            
            int num = top.first;
            char ch = top.second;
            
            if(num >= 1) pq.push({num-1, ch});
            
            count++;
        }
        
        int ans = 0;
        while(!pq.empty()){
            pair<int, int> top = pq.top();
            pq.pop();
            
            ans += (top.first * top.first);   
        }
        
        return ans;
    }
};