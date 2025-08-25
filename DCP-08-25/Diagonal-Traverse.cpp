// Company tags: Arcesium, Capital One, Zoho
class Solution {
public:
    // Time Complexity  : O(n*m*log(n+m)) , log because we are using ordered_map
    // Space Complexity : O(n*m)
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> result;
        map<int, vector<int>> mpp;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mpp[(i+j)].push_back(mat[i][j]);
            }
        }
        int count = 1;
        for(auto& mp : mpp){
            if(count % 2 == 0){
                for(int i = 0; i < mp.second.size(); i++){
                    result.push_back(mp.second[i]);
                }
            }else{
                for(int i = mp.second.size() - 1; i >= 0; i--){
                    result.push_back(mp.second[i]);
                }
            }
            count++;
        }

        return result;
    }
};