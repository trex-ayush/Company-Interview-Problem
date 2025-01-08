/*
    Problem Name: Count the number of possible triangles
    https://www.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1
    Company : Microsoft Amazon
*/

/*
    Approach 1 
    Time Complexity : O(n^2)
    Space Complexity : O(1)
*/
class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end()); // O(nlogn)
        int ans = 0;
        
        for(int k = n - 1; k >= 2; k--){
            int i = 0;
            int j = k - 1;
            while(i < j){
                if(arr[i] + arr[j] > arr[k]){
                    ans += j - i;
                    j--;
                }else{
                    i++;
                }
            }
        }
        return ans;
    }
};