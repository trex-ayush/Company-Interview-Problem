class Solution {
  public:
    int merge(vector<int>& arr, int start, int mid, int end) {
        int size_l = mid - start + 1;
        int size_r = end - mid;
        vector<int> left(size_l), right(size_r);
        
        int k = start;
        for (int i = 0; i < size_l; i++) {
            left[i] = arr[k++];
        }
        
        for (int i = 0; i < size_r; i++) {
            right[i] = arr[k++];
        }
        
        int i = 0, j = 0;
        k = start;
        int invCount = 0;
        
        while (i < size_l && j < size_r) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
                invCount += (size_l - i); 
            }
        }
        
        while (i < size_l) {
            arr[k++] = left[i++];
        }
        
        while (j < size_r) {
            arr[k++] = right[j++];
        }
        
        return invCount;
    }
    
    int mergeSort(vector<int>& arr, int start, int end) {
        int invCount = 0;
        
        if (start < end) {
            int mid = start + (end - start) / 2;
            
            invCount += mergeSort(arr, start, mid);    
            invCount += mergeSort(arr, mid + 1, end);  
            invCount += merge(arr, start, mid, end);
            
        }
        return invCount;
    }
    
    int inversionCount(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};
