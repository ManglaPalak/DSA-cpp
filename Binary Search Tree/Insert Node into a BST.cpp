TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root==NULL){
        TreeNode* root1=new TreeNode(val);
        return root1;
    }
    TreeNode* curr=root;
    if (curr->val > val){
        curr->left=insertIntoBST(root->left,val);
    }
    else{
        curr->right=insertIntoBST(root->right,val);
    }
    return root;
}
