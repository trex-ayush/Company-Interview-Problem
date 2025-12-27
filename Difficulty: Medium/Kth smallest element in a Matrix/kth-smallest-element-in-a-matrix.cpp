class Solution {
  public:
    int countElementLessOrEqual(vector<vector<int>> &matrix, int& mid){
        int n = matrix.size();
        int count = 0;
        
        int row = n - 1;
        int col = 0;
        
        while(row >= 0 && col < n){
            if(matrix[row][col] <= mid){
                count += row + 1;
                col++;
            }else row--;
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        
        int st = matrix[0][0];
        int en = matrix[n-1][n-1];
        
        
        while(st < en){
            int mid = st + (en - st)/2;
            int count = countElementLessOrEqual(matrix, mid);
            
            if(count < k) st = mid + 1;
            else en = mid;
            
        }
        
        return st;
    }
};