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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> st1, st2;
        st1.push(root1);
        st2.push(root2);
        while (!st1.empty() && !st2.empty()) {
            int l1 = -1, l2 = -1;
            while (!st1.empty() && l1 == -1) {
                TreeNode* root = st1.top();
                st1.pop();
                if (!root->left && !root->right) l1 = root->val;
                else {
                    if (root->right) st1.push(root->right);
                    if (root->left) st1.push(root->left);
                }
            }
            while (!st2.empty() && l2 == -1) {
                TreeNode* root = st2.top();
                st2.pop();
                if (!root->left && !root->right) l2 = root->val;
                else {
                    if (root->right) st2.push(root->right);
                    if (root->left) st2.push(root->left);
                }
            }
            if (l1 != l2) return false;
        }
        return st1.empty() && st2.empty();
    }
};

// dfs:

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<TreeNode*> s1(1, root1);
        vector<TreeNode*> s2(1, root2);
        while (!s1.empty() && !s2.empty()) {
            TreeNode* n1 = dfs(s1);
            TreeNode* n2 = dfs(s2);
            if (n1->val != n2->val) return false;
        }
        return s1.empty() && s2.empty();
    }
private:
    TreeNode* dfs(vector<TreeNode*>& s) {
        while (true) {
            TreeNode* root = s.back();
            s.pop_back();
            if (!root->left && !root->right) return root;
            if (root->right) s.push_back(root->right);
            if (root->left) s.push_back(root->left);
        }
    }
};