class Solution {
  public:
    int findSmallerNumber(vector<vector<int>> &mat, int& mid) {
        int count = 0;
        for (int i = 0; i < mat.size(); i++) {
            count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
        }
        return count;
    }

    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int totalElement = n*m;
        int medianIndex = totalElement/2;
        
        int st = 1;
        int en = 2000;
        
        while(st <= en){
            int mid = st + (en - st)/2;
            int elementLessThanMid = findSmallerNumber(mat, mid);
            
            if(elementLessThanMid <= medianIndex) st = mid + 1;
            else en = mid - 1;
        }
        return st;
    }
};
