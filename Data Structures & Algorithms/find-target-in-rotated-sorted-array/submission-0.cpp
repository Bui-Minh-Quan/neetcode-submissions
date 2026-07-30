class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2; 

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        int rotates = left;
        left = 0;
        right = nums.size() - 1;
        const int n = nums.size();

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[(mid + rotates) % n] == target) 
                return (mid + rotates) % n;
            
            if (nums[(mid + rotates) % n] < target) 
                left = mid + 1;
            else 
                right = mid - 1;
        }

 
        return -1;
    }
};
