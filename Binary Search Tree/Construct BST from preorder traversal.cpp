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
    TreeNode* buildBST(vector<int>& preorder,int& i,int mini,int maxi){
        if (i>=preorder.size()){
            return NULL;
        }
        if (preorder[i]<mini || preorder[i]>maxi){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=buildBST(preorder,i,mini,root->val);
        root->right=buildBST(preorder,i,root->val,maxi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini=INT_MIN;
        int maxi=INT_MAX;
        int i=0;
        return buildBST(preorder,i,mini,maxi);
    }
};
