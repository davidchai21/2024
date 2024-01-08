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
    int rangeSumBST(TreeNode* root, int low, int high) {
        return dfs(root, low, high);
    }
private:
    int dfs(TreeNode* root, const int& low, const int& high) {
        if (!root) return 0;
        if (root->val < low) return dfs(root->right, low, high);
        if (root->val > high) return dfs(root->left, low, high);
        return root->val + dfs(root->left, low, high) + dfs(root->right, low, high);
    }
};

// Iterative:

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        stack<TreeNode*> st;
        st.push(root);
        int res = 0;
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            if (!cur) continue;

            if (cur->val > low) st.push(cur->left);
            if (cur->val < high) st.push(cur->right);
            if (cur->val >= low && cur->val <= high) res += cur->val;
        }
        return res;
    }
};