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
    int maxLevelSum(TreeNode* root) {
       // Q1. Day -7/30
       queue<TreeNode*> q;
       int maxSum = INT_MIN;
       int minLevel = 1;
       int level = 1;
       q.push(root); 

       while(!q.empty()) {
        int sum = 0;
        int size = q.size();
        for(int i=0; i<size; i++) {
            TreeNode* fNode = q.front();
            q.pop();
            sum += fNode->val;

            if(fNode->left != NULL)  q.push(fNode->left);
            if(fNode->right != NULL)  q.push(fNode->right);
        }
        if(sum > maxSum) {
            maxSum = sum;
            minLevel = level;
        }
        level++;
       }
       return minLevel;
    }
};