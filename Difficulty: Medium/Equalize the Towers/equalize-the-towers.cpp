class Solution {
  public:
    int getCost(vector<int>& heights, vector<int>& cost, int k){
        int totalCost = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            totalCost += abs(heights[i] - k) * cost[i];
        }
        
        return totalCost;
    }
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = cost.size();
        
        int st = *min_element(heights.begin(), heights.end());
        int en = *max_element(heights.begin(), heights.end());
        int ans = 0;
        
        while(st <= en){
            int mid = st + (en - st)/2;
            
            int costMid   = getCost(heights, cost, mid); 
            int rightCost = getCost(heights, cost, mid+1); 
            
            if(costMid < rightCost){
                ans = costMid;
                en = mid - 1;
            }else st = mid + 1;
        }
        
        return ans;
    }
};
