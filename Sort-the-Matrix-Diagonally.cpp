// Company tags: Quora, Yandex
class Solution {
public:
    // Time Complexity  : O(n*m) + O(n*m*log(min(n, m))) + O(n*m) = O(n*m*log(min(n, m)))
    // Space Complexity : O(n*m)
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> result(n, vector<int>(m));
        map<int, vector<int>> mpp;
        
        for(int i = 0; i < n; i++){ 
            for(int j = 0; j < m; j++){
                mpp[(i-j)].push_back(mat[i][j]);
            }
        }
        // sorting time complexity : O(min(n, m)*log(min(n, m))*(n+m-1)) = O(n*m*log(min(n, m)))
        for(auto& mp : mpp){
            sort(mp.second.begin(), mp.second.end(), greater<int>());
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                result[i][j] = mpp[(i-j)].back();
                mpp[(i-j)].pop_back();
            }
        }


        return result;
    }
};