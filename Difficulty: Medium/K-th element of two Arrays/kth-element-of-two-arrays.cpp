class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int key) {
        int n = a.size();
        int m = b.size();
        int cnt = 0;
        int i = 0, j = 0;
        
        while(i < n && j < m){
            if(a[i] <= b[j]){
                cnt++;
                if(cnt == key) return a[i];
                i++;
            }else if(a[i] > b[j]){
                cnt++;
                if(cnt == key) return b[j];
                j++;
            }
        }
        while(i < n){
            cnt++;
            if(cnt == key) return a[i];
            i++;
        }
        while(j < m){
            cnt++;
            if(cnt == key) return b[j];
            j++;
        }
        return -1;
    }
};
