/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode * root, unordered_map<TreeNode *,TreeNode *> & mp){
        if(!root)return;
        if(root->left){
            mp[root->left]=root;
            traverse(root->left,mp);
        }
        if(root->right){
            mp[root->right]=root;
            traverse(root->right,mp);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode *> mp;
        unordered_map<TreeNode *,bool> vis;
        queue<TreeNode *> q;
        int level=0;
        traverse(root,mp);
        vis[target]=true;
        q.push(target);

        while(!q.empty()){
            int siz=q.size();
            while(siz--){
                if(level==k){
                    vector<int> ans;
                    while(!q.empty()){
                        ans.push_back(q.front()->val);
                        q.pop();
                    }
                    return ans;
                }

                TreeNode* node=q.front();q.pop();

                if(node->left && !vis[node->left]){
                    vis[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    vis[node->right]=true;
                    q.push(node->right);
                }
                if(mp[node] && !vis[mp[node]]){
                    vis[mp[node]]=true;
                    q.push(mp[node]);
                }
            }
            level++;
        }
        return {};

    }
};