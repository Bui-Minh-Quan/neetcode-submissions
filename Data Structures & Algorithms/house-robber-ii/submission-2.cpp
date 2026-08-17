class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        if (nums.size() == 2)
            return max(nums[0], nums[1]);

        const int n = nums.size();
        vector<pair<int, int>> arr(n);

        arr[0] = {nums[0], 0};

        for (int i = 1; i < n - 1; i++) {
            int first = arr[i - 1].second + nums[i];
            int second = max(arr[i - 1].first, arr[i - 1].second);

            arr[i] = {first, second};
        }

        int max_1 = max(arr[n - 2].first, arr[n - 2].second);

        arr[0] = {0, 0};

        for (int i = 1; i < n; i++) {
            int first = arr[i - 1].second + nums[i];
            int second = max(arr[i - 1].first, arr[i - 1].second);

            arr[i] = {first, second};
        }

        int max_2 = max(arr[n - 1].first, arr[n - 1].second);

        return max(max_1, max_2);

    }
};
