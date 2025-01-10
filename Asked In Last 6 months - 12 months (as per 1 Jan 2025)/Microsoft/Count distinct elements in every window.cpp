/*
    Problem Name: Geeksforgeeks Count distinct elements in every window
    https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
    Company : Amazon (1 year ago) , Accolite (1 year ago) , Microsoft (1 year ago)
*/

/*
    Approach 1 
    Time Complexity : O(n)
    Space Complexity : O(n)
*/
class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        int n = arr.size();
        int i = 0;
        int j = 0;
        
        while(j < n){
            mpp[arr[j]]++;
            
            if(j - i + 1 == k){
                ans.push_back(mpp.size());
                if(mpp[arr[i]] == 1){
                    mpp.erase(arr[i]);
                }else{
                    mpp[arr[i]]--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};