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
    void make_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);
        parent[root]=NULL;
        while(!q.empty()){
            TreeNode* top=q.front();
            q.pop();
            if(top->left){
                parent[top->left]=top;
                q.push(top->left);
            }
            if (top->right){
                parent[top->right]=top;
                q.push(top->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        make_parent(root,parent);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int curr=0;
        while(!q.empty()){
            int s=q.size();
            if (curr++ == k){
                break;
            }
            for(int i=0;i<s;i++){
                TreeNode* top=q.front();
                q.pop();
                visited[top]=true;
                if(top->left && visited[top->left]==false){
                    q.push(top->left);
                    visited[top->left]=true;
                }
                if (top->right && visited[top->right]==false){
                    q.push(top->right);
                    visited[top->right]=true;
                }
                if (parent[top] && visited[parent[top]]==false){
                    q.push(parent[top]);
                    visited[parent[top]]=true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* top=q.front();
            q.pop();
            ans.push_back(top->val);
        }
        return ans;
    }
};
