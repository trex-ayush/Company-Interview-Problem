class Solution {
public:
    vector<int> getNSL(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> left(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            
            if (st.empty()) left[i] = -1;
            else left[i] = st.top();
            
            st.push(i);
        }
        return left;
    }

    vector<int> getNSR(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> right(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            
            if (st.empty()) right[i] = n;
            else right[i] = st.top();
            
            st.push(i);
        }
        return right;
    }

    int findMaxArea(vector<int>& heights) {
        vector<int> NSR = getNSR(heights);
        vector<int> NSL = getNSL(heights);
        int area = 0;
        for (int i = 0; i < heights.size(); i++) {
            area = max(area, (heights[i] * (NSR[i] - NSL[i] - 1)));
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m);

        for (int i = 0; i < m; i++) {
            height[i] = (matrix[0][i] == '1') ? 1 : 0;
        }

        int maxArea = findMaxArea(height);

        for (int row = 1; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (matrix[row][col] == '0') {
                    height[col] = 0;
                } else {
                    height[col] += 1;
                }
            }
            maxArea = max(maxArea, findMaxArea(height));
        }
        return maxArea;
    }
};
