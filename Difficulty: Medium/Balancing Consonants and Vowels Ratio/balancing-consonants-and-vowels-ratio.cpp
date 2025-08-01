// similar to problem count subarray with sum 0
class Solution {
  public:
    bool isVowel(char& ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int countBalanced(vector<string>& arr) {
        int n = arr.size();
        int count = 0;
        int sum = 0;
        
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        
        for(auto& str : arr){
            for(auto& ch : str){
                if(isVowel(ch)) sum++;
                else sum--;
            }
            
            count += mpp[sum];
    
            mpp[sum]++;
        }
        
        
        return count;
    }
};