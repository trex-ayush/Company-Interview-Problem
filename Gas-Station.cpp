// Company tags: Amazon, BNY Mellon, Cisco, EPAM Systems, FactSet, Flipkart, Goldman Sachs, Google, Infosys, Microsoft, Morgan Stanley, Oracle, PhonePe, Uber, X, Zepto, Zoho
class Solution {
public:
    // T.C: O(n)
    // S.C: O(1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int totalKamai = accumulate(gas.begin(), gas.end(), 0);
        int totalKarch = accumulate(cost.begin(), cost.end(), 0);

        if(totalKamai < totalKarch) return -1;

        int total = 0;
        int resultIdx = 0;
        for(int i = 0; i < n; i++){
            total += gas[i] - cost[i];
            if(total < 0) {
                total = 0;
                resultIdx = i + 1;
            }
        }
        
        return resultIdx;
    }
};