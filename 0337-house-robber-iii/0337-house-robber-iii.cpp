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
    unordered_map<TreeNode*, int> mp;
    int solve(TreeNode* root) {
        // Base Case
        if(root == NULL)  return 0;

        // check already exist condition
        if(mp.count(root))  return mp[root];

        // if Rob 
        int opt1 = root->val;
        if(root->left)  opt1 += solve(root->left->left) + solve(root->left->right);
        if(root->right) opt1 += solve(root->right->left) + solve(root->right->right);

        // If Don't Rob
        int opt2 = solve(root->left) + solve(root->right);

        return mp[root] = max(opt1, opt2);
    }
    int rob(TreeNode* root) {
      // Abhi Code Karo
      int ans = solve(root);

      return ans;  
    }
};