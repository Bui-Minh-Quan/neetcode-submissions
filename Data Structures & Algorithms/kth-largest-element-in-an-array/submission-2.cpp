class Solution {
private:
    pair<int, int> partition3(vector<int>& nums, int left, int right) {
        int pivot = nums[(left + right) / 2];

        int lt = left;
        int i = left;
        int gt = right;

        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[lt]);
                ++i;
                ++lt;
            }
            else if (nums[i] > pivot) {
                swap(nums[i], nums[gt]);
                --gt;
            }
            else {
                ++i;
            }
        }

        return {lt, gt};
    }

    void quick_select(vector<int>& nums, int k, int left, int right) {
        while (left <= right) {
            auto [lt, gt] = partition3(nums, left, right);

            if (k < lt) {
                right = lt - 1;
            }
            else if (k > gt) {
                left = gt + 1;
            }
            else {
                return;
            }
        }
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int targetIdx = n - k;

        quick_select(nums, targetIdx, 0, n - 1);

        return nums[targetIdx];
    }
};