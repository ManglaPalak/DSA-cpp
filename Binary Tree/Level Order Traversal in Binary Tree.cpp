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
#include<queue>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> sub;
        while(!q.empty()){
            vector<int> sub;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* top=q.front();
                q.pop();
                sub.push_back(top->val);
                if (top->left){
                    q.push(top->left);
                }
                if (top->right){
                    q.push(top->right);
                }
            }
            ans.push_back(sub);
        }
        return ans;
    }
};
