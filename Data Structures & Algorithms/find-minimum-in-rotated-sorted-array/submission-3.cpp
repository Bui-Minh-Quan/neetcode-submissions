#include <vector>

class Solution {
public:
    int findMin(const std::vector<int>& nums) {
        // Fast I/O for LeetCode performance boost
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2; // Prevents overflow

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return nums[left];
    }
};