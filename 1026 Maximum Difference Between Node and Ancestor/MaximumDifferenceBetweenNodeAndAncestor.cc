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
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
private:
    int dfs(TreeNode* root, int min_val, int max_val) {
        if (!root) return 0;

        int res = max(abs(root->val - min_val), abs(max_val-root->val));
        int new_min = min(min_val, root->val);
        int new_max = max(max_val, root->val);
        return max(max(dfs(root->left, new_min, new_max), dfs(root->right, new_min, new_max)), res);
    }
};