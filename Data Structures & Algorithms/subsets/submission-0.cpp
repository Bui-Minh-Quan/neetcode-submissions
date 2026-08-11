class Solution {
private:
    vector<int> temp;
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int index) {
        if (index >= nums.size())
            return;

        for (int i = index; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            ans.push_back(temp);

            backtrack(nums, i + 1);

            temp.pop_back();
        }
        
    }


public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.push_back({});
        

        backtrack(nums, 0);
        return ans;
    }
};
