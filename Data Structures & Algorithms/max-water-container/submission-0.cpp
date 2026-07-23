class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int left = 0;
        int right = heights.size() - 1;

        while (left < right) {
            int min_height = min(heights[left], heights[right]);
            int width = right - left;
            ans = max(ans, min_height * width);

            if (heights[right] > heights[left])
                ++left;
            else 
                --right;
        }

        return ans;
    }
};
