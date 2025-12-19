class Solution {
  public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        sort(chairs.begin(), chairs.end());
        sort(passengers.begin(), passengers.end());
        
        int moves = 0;
        for(int i = 0; i < chairs.size(); i++){
            moves += abs(chairs[i] - passengers[i]);
        }
        return moves;
    }
};