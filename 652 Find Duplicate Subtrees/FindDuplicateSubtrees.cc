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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, pair<bool, TreeNode*>> m;
        dfs(root, m);
        
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second.first) {
                res.push_back(it->second.second);
            }
        }
        return res;
    }
private:
    string dfs(TreeNode* root, unordered_map<string, pair<bool, TreeNode*>>& m) {
        if (!root) return "";
        
        string left = dfs(root->left, m);
        string right = dfs(root->right, m);
        string res = "("+left+")"+to_string(root->val)+"("+right+")";
        if (m.find(res) != m.end()) m[res].first = true;
        else m[res] = make_pair(false, root);
        return res;
    }
};