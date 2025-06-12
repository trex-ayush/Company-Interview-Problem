class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int largest = INT_MIN;
        int secLarg = INT_MIN;
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > largest) {
                secLarg = largest;
                largest = arr[i];
            }else if(arr[i] < largest && arr[i] > secLarg){
                secLarg = arr[i];
            }
        }
        return secLarg == INT_MIN ? -1 : secLarg;
    }
};