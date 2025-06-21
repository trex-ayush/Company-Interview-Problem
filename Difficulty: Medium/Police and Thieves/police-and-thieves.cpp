class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size();
        int count = 0;
        
        queue<int> police, thief;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P') police.push(i);
            else thief.push(i);
            
            // Try matching police and thieves within range
            while (!police.empty() && !thief.empty()) {
                int pIdx = police.front();
                int tIdx = thief.front();
                
                if (abs(pIdx - tIdx) <= k) {
                    // They can be matched
                    police.pop();
                    thief.pop();
                    count++;
                } else if (tIdx < pIdx) {
                    // Thief too far left, discard
                    thief.pop();
                } else {
                    // Police too far left, discard
                    police.pop();
                }
            }
        }
        return count;
    }
};
