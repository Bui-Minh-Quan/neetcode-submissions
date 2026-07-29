class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;

        const int n = heights.size();
        for (int i = 0; i <= n; i++) {
            int current_height = (i == n) ? 0 : heights[i];

            while (!st.empty() && current_height < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;

                ans = max(ans, height * width);
            }

            st.push(i);
        
        }


        return ans;

    }
};




