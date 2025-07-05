class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        int result = -1;
        unordered_map<int,int> mpp;

        for(int i = 0; i < n; i++){
            mpp[arr[i]]++;
        }
        for(auto& mp : mpp){
            if(mp.first == mp.second) {
                result = max(result, mp.first);
            }
        }

        return result;
    }
};