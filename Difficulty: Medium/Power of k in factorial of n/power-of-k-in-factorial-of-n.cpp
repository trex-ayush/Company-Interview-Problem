class Solution {
  public:
    int maxKPower(int n, int k) {
        unordered_map<int, int> primeFactors;
        int num = k;
        
        for (int i = 2; i * i <= num; ++i) {
            while (k % i == 0) {
                primeFactors[i]++;
                k /= i;
            }
        }
        if (k > 1) {
            primeFactors[k]++;
        }

        int result = INT_MAX;

        for (auto it : primeFactors) {
            int prime = it.first;
            int powerInK = it.second;

            int count = 0;
            int tempN = n;
            while (tempN > 0) {
                count += tempN / prime;
                tempN /= prime;
            }

            result = min(result, count / powerInK);
        }

        return result;
    }
};