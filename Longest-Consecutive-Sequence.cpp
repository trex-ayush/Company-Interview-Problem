// Company tags: ByteDance, Cisco, DE Shaw, EPAM Systems, Google, IBM, Infosys, Lyft, Oracle, Paytm, SAP, ServiceNow, Swiggy, TCS, TikTok, Turing, Walmart Labs, Yandex, Zepto, Zoho
class Solution {
public:
    // T.C: O(n)
    // S.C: O(n)
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> mpp(nums.begin(), nums.end());

        int maxLen = 0;

        for (int num : mpp) {
            if (mpp.find(num - 1) == mpp.end()) {
                int len = 1;
                int curr = num;

                while (mpp.find(curr + 1) != mpp.end()) {
                    curr++;
                    len++;
                }

                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};