
class Solution {
  public:
    void solve(vector<int>& arr, int idx, string& temp, vector<string>& res, vector<string> mapping){
        if(idx >= arr.size()){
            res.push_back(temp);
            return;
        }
        
        if(arr[idx] <= 1) solve(arr, idx+1, temp, res, mapping);
        string str = mapping[arr[idx]];
        for(auto& ch : str){
            temp += ch;
            solve(arr, idx+1, temp, res, mapping);
            temp.pop_back();
        }
    }
    vector<string> possibleWords(vector<int> &arr) {
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string temp = "";
        
        solve(arr, 0, temp, res, mapping);
        
        return res;
    }
};