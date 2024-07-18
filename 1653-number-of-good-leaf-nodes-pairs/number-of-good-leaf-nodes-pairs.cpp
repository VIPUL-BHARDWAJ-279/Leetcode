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
    int ans=0;
    vector<int> solve(TreeNode* root, int distance){
        if(!root)return {};

        //left sub tree return the list of distances of the current node to all the leaf nodes.
        auto leftLeaves=solve(root->left,distance);

        //right sub tree return the list of distances of the current node to all the leaf nodes.
        auto rightLeaves=solve(root->right,distance);

        for(auto x:leftLeaves){
            for(auto y:rightLeaves){
                if(x+y<=distance)ans++;
            }
        }

        vector<int> combinedLeaves;
        for(auto x:leftLeaves)combinedLeaves.push_back(x+1);
        for(auto y:rightLeaves)combinedLeaves.push_back(y+1);

        if(combinedLeaves.size()==0)combinedLeaves.push_back(1);

        return combinedLeaves;

    }
    int countPairs(TreeNode* root, int distance) {
        solve(root,distance);
        return ans;
    }
};