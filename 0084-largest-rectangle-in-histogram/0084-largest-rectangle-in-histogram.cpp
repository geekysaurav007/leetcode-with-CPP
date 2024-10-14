class Solution {
public:
    void prevSmallerElements(vector<int>& prev, vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() and heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                prev[i] = -1;
            } else {
                prev[i] = st.top();
            }
            st.push(i);
        }
    }
    void nextSmallerElements(vector<int>& next, vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() and heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                next[i] = heights.size();
            } else {
                next[i] = st.top();
            }
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n);
        nextSmallerElements(next, heights);
        vector<int> prev(n);
        prevSmallerElements(prev, heights);
        int area = INT_MIN;
        for (int i = 0; i < n; i++) {
            int l = heights[i];
            int b = ( next[i]-prev[i] - 1);
            area = max(area, l * b);
        }
        return area;
    }
};