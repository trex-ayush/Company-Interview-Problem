// Company tags: Accenture, Atlassian
class Solution {
public:
    // Time Complexity  : O(n)
    // Space Complexity : O(1)
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxi = INT_MIN;
        int maxArea = INT_MIN;

        for(auto& dimension : dimensions){
            int l = dimension[0];
            int b = dimension[1];

            int dia = l*l + b*b;
            int area = l*b;

            if(dia > maxi) {
                maxi = dia;
                maxArea = area;
            } else if(dia == maxi) {
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};