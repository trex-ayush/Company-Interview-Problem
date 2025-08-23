// Company tags: Airbnb, Booking.com, ByteDance, Citadel, DE Shaw, eBay, Goldman Sachs, IBM, Karat, Myntra, Nvidia, Oracle, PayPal, PhonePe, SAP, Salesforce, ServiceNow, Walmart Labs

// Time Complexity for bottom up : O(n*m)
// Space Complexity for bottom up : O(n*m)

// Time Complexity for Rec + Memo : O(n*m)
// Space Complexity: O(n * m) for memo + O(n + m) call stack (worst case)

class Solution {
public:
    /* ------ Bottom Up ------ */
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> t(n, vector<int>(m, 0));
        int result = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0) {
                    t[i][j] = mat[i][j] == '0' ? 0 : 1;
                }else if(mat[i][j] == '1'){
                    t[i][j] = 1 + min({t[i-1][j], t[i-1][j-1], t[i][j-1]});
                }
                result = max(result, t[i][j]);
            }
        }
        return result * result;
    }
    /* ------ Recursion + Memoization ------ */
    // int n, m;
    // int t[301][301];
    // int solve(int i, int j, vector<vector<char>>& mat){
    //     if( i >= n || j >= m) return 0;
    //     if(mat[i][j] == '0') return 0;
        
    //     if(t[i][j] != -1) return t[i][j];

    //     int down = solve(i + 1, j, mat);
    //     int righ = solve(i, j + 1, mat);
    //     int diag = solve(i + 1, j + 1, mat);

    //     return t[i][j] = 1 + min({down, righ, diag});
    // }
    // int maximalSquare(vector<vector<char>>& mat) {
    //     n = mat.size();
    //     m = mat[0].size();
    //     memset(t, -1, sizeof(t));
    //     int result = 0;

    //     for(int i = 0; i < n; i++){
    //         for(int j = 0; j < m; j++){
    //             if(mat[i][j] == '1'){
    //                 result = max(result, solve(i, j, mat));
    //             }
    //         }
    //     }
    //     return result * result;
    // }

};