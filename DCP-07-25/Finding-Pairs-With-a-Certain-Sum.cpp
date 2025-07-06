class FindSumPairs {
public:
    // Time Comlpexity  : O(n)
    // Space Comlpexity : O(n)
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int,int> mpp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(auto& num : nums2) mpp[num]++;
        
    }
    
    void add(int index, int val) {
        int prevVal = nums2[index];
        mpp[prevVal]--;
        nums2[index] = nums2[index] + val;
        mpp[nums2[index]]++;
        return;
    }
    
    int count(int tot) {
        int n = nums1.size();
        int result = 0;

        for(int i = 0; i < n; i++){
            int num = nums1[i];
            int req = tot - num;
            result += mpp[req];
        }

        return result;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */