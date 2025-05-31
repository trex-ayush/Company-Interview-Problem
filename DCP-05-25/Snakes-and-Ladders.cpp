class Solution {
public:
    pair<int,int> findRowAndCol(int& num, int& n) {
        int rowFromTop = (num-1)/n;
        int rowFromBottom = (n-1) - rowFromTop;
        // int colLeftToRight = (num-1)%n;
        // int colRightToLeft = (n-1) - colLeftToRight;
        int col = (num - 1) % n;

        // Flip column direction based on board size and row index
        if ((n % 2 == 1 && rowFromBottom % 2 == 1) || (n % 2 == 0 && rowFromBottom % 2 == 0)){
            col = n - 1 - col;
        }

        return {rowFromBottom, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int steps = 0;
        q.push(1);
        visited[n - 1][0] = true;

        while (!q.empty()) {
            int k = q.size();
            while (k--) {
                int x = q.front();
                q.pop();

                if (x == n * n) return steps;
                // x+1, x+2, x+3, x+4 ...
                // 1+1, 1+2, 1+3, 1+4 ...
                for (int i = 1; i <= 6; i++) {
                    int value = x + i;
                    if (value > n * n) break;
                    pair<int, int> rowAndCol = findRowAndCol(value, n);
                    int row = rowAndCol.first;
                    int col = rowAndCol.second;

                    if (visited[row][col]) continue;
                    visited[row][col] = true;
                    if (board[row][col] == -1) q.push(value);
                    else q.push(board[row][col]);
                }
            }
            steps++;
        }
        return -1;
    }
};
