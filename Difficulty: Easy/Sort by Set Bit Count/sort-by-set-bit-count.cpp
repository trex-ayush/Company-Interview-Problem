class Solution {
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
      map<int, vector<int>> mp;
      for(auto i: arr){
          int val= i;
          int cnt= 0;
          while(val){
              if(val & 1){
                  cnt++;
              }
              val= val >>1;
          }
          mp[cnt].push_back(i);
      }
      vector<int> ans;
      for(auto i= mp.rbegin(); i != mp.rend(); i++){
          for(auto j: i->second){
              ans.push_back(j);
          }
      }
      return ans;
        
        
    }
};