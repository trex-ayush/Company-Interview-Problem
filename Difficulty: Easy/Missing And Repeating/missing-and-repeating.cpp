class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq (n+1 , 0);
        
        for(int i = 0; i < n; i++){
            freq[arr[i]]++;
        }
        
        int missing = -1;
        int repeating = -1;
        
        for(int i = 1; i < n+1; i++){
            if(freq[i] == 2){
                repeating = i;
            }else if(freq[i] == 0){
                missing = i;
            }
            
            if(repeating != -1 && missing != -1) return {repeating, missing};
        }
        return {repeating, missing};
    }
};