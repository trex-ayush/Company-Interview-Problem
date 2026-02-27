class Solution {
public:
    int countSquare(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int result = 0;
        
        // Row-wise prefix sum
        for(int r = 0; r < rows; r++) {
            for(int c = 1; c < cols; c++) {
                matrix[r][c] += matrix[r][c-1];
            }
        }
        
        // Try all possible starting columns
        for(int startCol = 0; startCol < cols; startCol++) {
            for(int currCol = startCol; currCol < cols; currCol++) {
                
                int width = currCol - startCol + 1;
                
                // If width > rows, cannot form square
                if(width > rows) continue;
                
                // Compressed column sums
                vector<int> colSum(rows, 0);
                for(int r = 0; r < rows; r++) {
                    colSum[r] = matrix[r][currCol] - (startCol > 0 ? matrix[r][startCol-1] : 0);
                }
                
                // Sliding window of height = width
                int windowSum = 0;
                for(int r = 0; r < rows; r++) {
                    windowSum += colSum[r];
                    
                    if(r >= width) windowSum -= colSum[r - width];
                    
                    if(r >= width - 1 && windowSum == target) {
                        result++;
                    }
                }
            }
        }
        
        return result;
    }
};