class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;

    void backtrack(vector<int>& nums, int index) {
        if (index >= nums.size())
            return;
        
        for (int i = index; i < nums.size(); i++) {
            // check duplicates in the same recurssion level
            if (i > index && nums[i] == nums[i - 1])
                continue;
            
            temp.push_back(nums[i]);
            ans.push_back(temp);

            backtrack(nums, i + 1);

            temp.pop_back();
        }
    }

public:

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ans.push_back({});
        backtrack(nums, 0);

        return ans;
    }
};
