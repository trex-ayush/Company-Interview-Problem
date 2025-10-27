class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        int n = arr1.size();
        int m = arr2.size();
        for(int i= 0 ; i<k && i < n ; i++){
            for(int j = 0 ; j < k && j < m ; j++){
                long long sum = arr1[i]+arr2[j];
                if(pq.size() < k)pq.push({sum,{arr1[i],arr2[j]}});
                else if (pq.size() == k){
                    int s = pq.top().first;
                    if(s > sum ){
                        pq.pop();
                        pq.push({sum,{arr1[i],arr2[j]}});
                    }
                }
            }
        }
        vector<vector<int>> ans ;
        for (int i = 0 ; i < k ; i++){
            if(pq.empty()) break;
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
