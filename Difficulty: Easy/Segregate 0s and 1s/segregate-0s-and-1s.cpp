class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int i = 0;
        int j = arr.size() - 1;
        
        while(i < j){
            if(arr[i] == 1 && arr[j] == 0){
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
            else if(arr[i] == 0) i++;
            else if(arr[j] == 1) j--;
        }
    }
};