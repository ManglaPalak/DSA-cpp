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
    TreeNode* createTree(vector<int>& preorder,int pstart,int pend,vector<int>& inorder,int istart,int iend,unordered_map<int,int>& inmp){
        if (pstart>pend || istart>iend){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[pstart]);
        int iroot=inmp[preorder[pstart]];
        int numleft=iroot-istart;
        root->left=createTree(preorder,pstart+1,pend+numleft,inorder,istart,iroot-1,inmp);
        root->right=createTree(preorder,pstart+numleft+1,pend,inorder,iroot+1,iend,inmp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inmp;
        for(int i=0;i<inorder.size();i++){
            inmp[inorder[i]]=i;
        }
        TreeNode* root=createTree(preorder,0,preorder.size()-1,inorder,0,inorder.size(),inmp);
        return root;
    }
};
