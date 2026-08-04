// Fast I/O trick
auto speedup = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();
            vector<int> current_level;
            current_level.reserve(level_size); // Avoid dynamic resizing inside the loop

            for (int i = 0; i < level_size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                current_level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(move(current_level)); // Move to avoid copying memory
        }

        return ans;
    }
};