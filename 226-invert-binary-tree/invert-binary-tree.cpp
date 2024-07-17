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
    TreeNode* solve(TreeNode* root){
        if(!root)return NULL;

        TreeNode * rightChild=solve(root->right);
        TreeNode * leftChild=solve(root->left);
        root->left=rightChild;
        root->right=leftChild;

        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        return solve(root);
    }
};