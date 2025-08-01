class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);

        for(int i = 0; i < n; i++){
            vector<int> temp(i+1, 1);
            for(int j = 0; j < i+1; j++){
                if(j != 0 && j != i){
                    temp[j] = ans[i-1][j] + ans[i-1][j-1];
                }
            }
            ans[i] = temp;
        }

        return ans;
    }
};