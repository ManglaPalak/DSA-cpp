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
    bool isSame(TreeNode* p,TreeNode* q){
        if (p==NULL && q==NULL){
            return true;
        }
        if ((p==NULL && q!=NULL) || (p!=NULL && q==NULL)){
            return false;
        }
        bool lefr=isSame(p->left,q->right);
        bool rigl=isSame(p->right,q->left);
        bool val=p->val==q->val;
        return (lefr && rigl && val);
    }
    bool isSymmetric(TreeNode* root) {
        if (root==NULL){
            return true;
        }
        return isSame(root->left,root->right);
    }
};
