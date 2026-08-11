#include <vector>
#include <algorithm>

class Solution {
private:
    std::vector<int> temp;
    std::vector<std::vector<int>> ans;

    void backtrack(const std::vector<int>& candidates, int index, int target) {
        // Base case: target matched!
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            // 1. Early Pruning: Since array is sorted, no subsequent element can fit
            if (candidates[i] > target) {
                break;
            }

            // 2. Skip duplicate choices at the SAME recursion depth
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Choose
            temp.push_back(candidates[i]);
            
            // Explore (move to next index `i + 1`)
            backtrack(candidates, i + 1, target - candidates[i]);
            
            // Un-choose (Backtrack)
            temp.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        // Sort first to bring duplicates together and allow early breaking
        std::sort(candidates.begin(), candidates.end());

        backtrack(candidates, 0, target);

        return ans;
    }
};