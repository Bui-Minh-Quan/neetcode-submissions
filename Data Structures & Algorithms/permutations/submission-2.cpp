class Solution {
private:
    std::vector<std::vector<int>> ans;

    void backtrack(std::vector<int>& nums, int start) {
        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            std::swap(nums[start], nums[i]);
            backtrack(nums, start + 1);
            std::swap(nums[start], nums[i]); // Backtrack
        }
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};