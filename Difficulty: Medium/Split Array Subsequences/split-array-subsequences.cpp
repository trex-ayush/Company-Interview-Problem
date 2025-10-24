class Solution {
  public:
    /**
    The main intuition here is that its always better to extend 
    the subsequnce because it avoids the situation where a
    subsequence would have less than k elements if we try to create
    a new subsequence of length k every time.
    **/
    bool isPossible(vector<int>& arr, int k) {
        map<int,int> freq;
        for(int num: arr)freq[num]++;
        
        map<int,int> end;
        for(int num: arr){
            if(freq[num] == 0)continue;
            else if(end[num-1]>0){
                end[num-1]--;
                end[num]++;
                freq[num]--;
            }
            else{
                for(int i = 0;i<k;i++){
                    if(freq[num+i] == 0)return false;
                    freq[num+i]--;
                }
                end[num+k-1]++;
            }
        }
        return true;
    }
};
