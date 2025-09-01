class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> freq;      // number -> frequency
        map<int, set<int>> bucket;        // frequency -> set of numbers
        int maxFreq = 0, sum = 0;
        
        auto add = [&](int x) {
            int f = freq[x]++;
            if (f > 0) bucket[f].erase(x);
            bucket[f+1].insert(x);
            if (bucket[f].empty()) bucket.erase(f);
            maxFreq = max(maxFreq, f+1);
        };
        
        auto remove = [&](int x) {
            int f = freq[x]--;
            bucket[f].erase(x);
            if (bucket[f].empty()) bucket.erase(f);
            if (f-1 > 0) bucket[f-1].insert(x);
            if (bucket[f-1].empty()) bucket.erase(f-1);
            if (bucket[maxFreq].empty()) maxFreq--;
        };
        
        // build first window
        for (int i = 0; i < k; i++) add(arr[i]);
        
        sum += *bucket[maxFreq].begin();
        
        // slide window
        for (int i = k; i < n; i++) {
            add(arr[i]);
            remove(arr[i-k]);
            sum += *bucket[maxFreq].begin();
        }
        
        return sum;
    }
};