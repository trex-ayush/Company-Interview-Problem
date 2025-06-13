class Solution {
public:
    bool isPossible(vector<int>& nums, int p, int& val, int& n){
        int count = 0;
        int i = 0;

        while(i < n - 1){
            if(abs(nums[i+1] - nums[i]) <= val){
                count++;
                i += 2;
            }else i++;
        }

        return count >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int st = 0;
        int en = nums[n-1];
        int ans = 0;

        while(st <= en){
            int mid = st + (en - st)/2;

            if(isPossible(nums, p, mid, n)){
                ans = mid;
                en = mid - 1;
            }else st = mid + 1;
        }
        return ans;
    }
};