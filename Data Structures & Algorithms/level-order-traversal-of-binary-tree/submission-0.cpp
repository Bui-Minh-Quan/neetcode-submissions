/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    unordered_map<int, vector<int>> mp;

    void helper(TreeNode* root, int level = 0) {
        if (!root)
            return;

      
        mp[level].push_back(root -> val);
        
        
        helper(root -> left, level + 1);
        helper(root -> right, level + 1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        helper(root, 0);
        vector<vector<int>> ans;

        int i = 0;

        while (mp.contains(i)) {
            ans.push_back(mp[i]);
            ++i;
        }

        return ans;

    }
};




