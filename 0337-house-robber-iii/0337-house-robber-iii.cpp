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
    // Dp step1 create unordered map node->val ke liye
    // for dp on Tree
    unordered_map<TreeNode*, int> mp;
    int solve(TreeNode* root) {
        // Base Case
        if(root == NULL)  return 0;
        
        // dp step2: check condition after base case
        // check already exist condition
        if(mp.count(root)) return mp[root];

        // case1: rob the current node
        int opt1 = root->val;
        if(root->left)  opt1 += solve(root->left->left) + solve(root->left->right);
        if(root->right) opt1 += solve(root->right->left) + solve(root->right->right);

        // Case2: Not rob the current node
        int opt2 = solve(root->left) + solve(root->right);

        // dp step3: return krne se pahle dp mai store karao
        return mp[root] = max(opt1, opt2);
    }
    int rob(TreeNode* root) {
       // Abhi Code Karo
       int ans = solve(root);
    
       return ans;
    }
};

// Tc => O(N)
// SC => O(N)