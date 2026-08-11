class Solution {
private:
    vector<int> temp;
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, unordered_map<int, bool> visited) {

        if (temp.size() >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        

        for (const auto& num:nums) {
            if (visited[num])
                continue;
            
            visited[num] = true;
            temp.push_back(num);
            backtrack(nums, visited);

            temp.pop_back();
            visited[num] = false;
        }
    }


public:
    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, bool> visited;

        backtrack(nums, visited);

        return ans;
    }
};





