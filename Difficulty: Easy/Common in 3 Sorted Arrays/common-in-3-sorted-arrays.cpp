class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        int n1 = a.size();
        int n2 = b.size();
        int n3 = c.size();
        int i = 0;
        int j = 0;
        int k = 0;
        vector <int> ans;
        while(i<n1 && j<n2 && k<n3){
            if(a[i] ==  b[j] && a[i] == c[k]){
                ans.push_back(a[i]);
                i++;
                j++;
                k++;
            }else if( a[i] < b[j]){
                i++;
            }
            else if( b[j] < c[k]){
                j++;
            }else {
                k++;
            }
        }
        vector<int> result;
        if (ans.size() > 0) {
            result.push_back(ans[0]);
            for (int i = 1; i < ans.size(); i++) {
                if (ans[i] != ans[i - 1]) {
                    result.push_back(ans[i]);
                }
            }
        } 
        return result;
    }
};