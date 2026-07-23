class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = 1;
        int ans = 0;
        const int n = height.size();

        vector<int> max_left;
        vector<int> max_right;

        max_left.push_back(0);
        max_right.push_back(0);

 
     
        for (int i = 1; i < n; i++) {
            // The height bar so far from the left
            if (height[i - 1] > max_left.back())
                max_left.push_back(height[i - 1]);
            else
                max_left.push_back(max_left.back()); 

            if (height[n - i] > max_right.back())
                max_right.push_back(height[n - i]);
            else 
                max_right.push_back(max_right.back());
        }

        reverse(max_right.begin(), max_right.end());

        for (int i = 0; i < n; i++) {
            int h = min(max_left[i], max_right[i]);
            ans += max(0, h - height[i]);
        }


        
        return ans;
    }
};
