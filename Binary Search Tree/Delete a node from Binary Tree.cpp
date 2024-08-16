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
    int maxValueBST(TreeNode* root){
        TreeNode* temp=root;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==NULL){
            return root;
        }
        if (root->val==key){
            //0 child
            if (root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }

            //1 child
            // -> LEFT CHILD
            if (root->left!=NULL && root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            // -> RIGHT CHILD
            if (root->left==NULL && root->right!=NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }

            //2 children
            if (root->left!=NULL && root->right!=NULL){
                TreeNode* temp = root->left;
                while(temp->right != NULL){
                    temp = temp->right;
                }
                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);
                return root;
            }
        }
        if (root->val > key){
            root->left=deleteNode(root->left,key);
            return root;
        }
        else{
            root->right=deleteNode(root->right,key);
            return root;
        }
    }
};
