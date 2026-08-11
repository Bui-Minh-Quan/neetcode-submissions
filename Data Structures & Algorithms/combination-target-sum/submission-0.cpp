class Solution {
private:
    vector<int> temp;
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int index, int curr_sum, int target) {
        if (curr_sum == target)
            ans.push_back(temp);

        if (curr_sum > target)
            return;
        
        for (int i = index; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            backtrack(nums, i, curr_sum + nums[i], target);
            
            temp.pop_back();
        }

    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, 0, 0, target);
        return ans;
    }
};
