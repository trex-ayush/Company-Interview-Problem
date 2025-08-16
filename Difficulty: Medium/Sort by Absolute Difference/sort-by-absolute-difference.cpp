class Solution {
  public:
    void rearrange(vector<int> &arr, int k) {
        stable_sort(arr.begin(),arr.end(),[k](int a,int b){
           return abs(a-k) < abs(b-k);
        });
    }
};