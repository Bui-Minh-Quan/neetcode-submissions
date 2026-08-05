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
    int ans;
    int count = 0;

    void add_nodes(TreeNode* root, int& target) {
        if (!root)
            return;

        add_nodes(root -> left, target);
        ++count;

        if (count == target) {
            ans = root -> val;
            return;
        }

        add_nodes(root -> right, target);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        add_nodes(root, k);
        return ans;
    }
};





