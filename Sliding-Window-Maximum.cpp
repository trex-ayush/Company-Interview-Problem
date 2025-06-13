// Company Tags: Zenefits, Booking.com, MongoDB, Autodesk, DE Shaw, Nutanix, Citadel, Coupang, Flipkart, TCS, Infosys, Media.net, Goldman Sachs, Yandex, Rubrik, DoorDash
class Solution {
public:
    // T.C: O(n)
    // S.C: O(k)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;  // storing indexs

        for(int i = 0; i < n; i++){
            // Remove idx that are out of the current window
            while(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }
            
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);
            
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};