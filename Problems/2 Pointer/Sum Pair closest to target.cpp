/*
    Problem Name: Sum Pair closest to target
    https://www.geeksforgeeks.org/problems/pair-in-array-whose-sum-is-closest-to-x1124/1
    Company : Ola
*/

/*
    Approach 1 
    Time Complexity : O(nlogn)
    Space Complexity : O(1)
*/
class Solution{   
public:
    vector<int> sumClosest(vector<int>arr, int x){
        sort(arr.begin() , arr.end());
        int n = arr.size();
        
        int i = 0;
        int j = n - 1;
        int diff = INT_MAX;
        vector<int> ans(2, 0);
        
        if(arr.size() == 1) return {};
        
        while(i<j){
            int sum = arr[i] + arr[j];
            if(diff > abs(sum-x)){
                diff = min(diff, abs(x - sum)); 
                ans[0] = arr[i];
                ans[1] = arr[j];
            }else if (sum < x) {
                i++;
            } else if(sum > x){
                j--;
            }else return ans;
        }
        return ans;
    }
    
};
