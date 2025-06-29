// Company tags: Amazon, Turing, Snap
class Solution {
public:
    // T.C: O(nlogn + n) = O(nlogn)
    // S.C: O(n)
    int numSubseq(vector<int>& nums, int& target) {
        int n = nums.size();
        int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());  // O(nlogn)

        int st = 0;
        int en = n - 1;
        int result = 0;

        vector<int> power(n, 1);
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        while(st <= en){  // O(n)
            int sum = nums[st] + nums[en];
            if(sum > target){
                en--;
            }else if(sum <= target){
                int diff = en - st;
                result = (result + power[en - st]) % MOD;
                st++;
            }
        }

        return result;
    }
};