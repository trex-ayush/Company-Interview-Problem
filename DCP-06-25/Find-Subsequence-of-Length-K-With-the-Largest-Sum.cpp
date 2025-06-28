// Company tags: Accenture, Oracle
class Solution {
public:
    // T.C: O(nlogn + klogk)
    // S.C: O(n)
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> nums1;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            nums1.push_back({nums[i], i});
        }
        sort(nums1.begin(), nums1.end(), greater<>());  // O(nlogn)

        nums1.resize(k);

        sort(nums1.begin(), nums1.end(), [&](auto a, auto b){
            return a.second < b.second;
        });  // O(klogk)

        vector<int> ans;

        for(auto& num : nums1){   // o(k)
            ans.push_back(num.first);
        }

        return ans;
    }
};