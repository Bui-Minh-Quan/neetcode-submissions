#include <vector>

class Solution {
private:
    std::vector<int> temp;
    std::vector<std::vector<int>> ans;

    void backtrack(const std::vector<int>& nums, std::vector<bool>& visited) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // Iterate by INDEX 'i', not by value 'num'
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) {
                continue;
            }

            visited[i] = true;
            temp.push_back(nums[i]);
            
            backtrack(nums, visited);

            temp.pop_back();
            visited[i] = false;
        }
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<bool> visited(n, false);

        backtrack(nums, visited);

        return ans;
    }
};