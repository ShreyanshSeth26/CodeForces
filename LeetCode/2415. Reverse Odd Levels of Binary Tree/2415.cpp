class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;
        dfs(root->left, root->right, 1);
        return root;
    }
    
private:
    void dfs(TreeNode* a, TreeNode* b, int lvl) {
        if (!a) return;
        if (lvl & 1) {
            std::swap(a->val, b->val);
        }
        dfs(a->left,  b->right, lvl+1);
        dfs(a->right, b->left,  lvl+1);
    }
};
