class Solution {
  public:
    // Approach 2: Optimal
    // T.C: O(nlogn + n*k) = O(nlogn)
    // S.C: O(n)
    bool validgroup(vector<int> &arr, int k) {
        int n = arr.size();
        if(n % k) return false;
        map<int, int> freq;
        
        for (int num : arr) {
            freq[num]++;
        }
        
        for (auto pair : freq) {
            int num = pair.first;
            int count = pair.second;
            
            if (count > 0) {
                for (int i = 0; i < k; i++) {
                    int current = num + i;
                    if (freq[current] < count) {
                        return false;
                    }
                    freq[current] -= count;
                }
            }
        }
    
        return true;
    }
    
    
    /*--------------------------------------------------*/
    // Approach 1: Brute force
    // T.C: O(n^2 + nlogn) = O(n^2)
    // S.C: O(1)
    // bool validgroup(vector<int> &arr, int k) {
    //     int n = arr.size();
    //     if(n % k) return false;
        
    //     sort(arr.begin(), arr.end());
        
    //     for(int i = 0; i < n; i++){
    //         if(arr[i] == -1) continue;
            
    //         int curr = arr[i];
    //         int count = 0;
            
    //         for(int j = i; j < n; j++){
    //             if(arr[j] == curr){
    //                 curr++;
    //                 count++;
    //                 arr[j] = -1;
    //                 if(count == k) break;
    //             }
    //         }
            
    //         if(count != k) return false;
    //     }
        
    //     return true;
    // }
};
