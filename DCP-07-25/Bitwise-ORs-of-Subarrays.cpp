class Solution {
public:
    // Time Complexity:  O(n × log M)
    // Space Complexity: O(n × log M)
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> prev;
        unordered_set<int> curr;
        unordered_set<int> result;

        for(int i = 0; i < n; i++){
            for(auto& ele : prev){
                curr.insert(ele|arr[i]);
                result.insert(ele|arr[i]);
            }
            curr.insert(arr[i]);
            result.insert(arr[i]);
            prev = curr;
            curr.clear();
        }
        return result.size();
    }   
};