// Compant tags: Amazon, ConsultAdd, PhonePe, Tencent, Flipkart, Yandex, Accenture, Goldman Sachs
class Solution {
public: 
    /*
    Approach 2
        T.C: O(3n) = O(n)
        S.C: O(n)
    */
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> count(n,1);

        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                count[i] = max(count[i] , count[i-1] + 1);
            }
        }
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                count[i] = max(count[i] , count[i+1] + 1);
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            ans += count[i];
        }

        return ans;
    }

    /* ---------------------------------------------- */

    /*
    Approach 1
        T.C: O(3n) = O(n)
        S.C: O(2n) = O(n)

    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> L2R(n,1);
        vector<int> R2L(n,1);

        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                L2R[i] = max(L2R[i] , L2R[i-1] + 1);
            }
        }
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                R2L[i] = max(R2L[i] , R2L[i+1] + 1);
            }
        }

        int count = 0;

        for(int i = 0; i < n; i++){
            count += max(L2R[i], R2L[i]);
        }

        return count;
    }
    */
};