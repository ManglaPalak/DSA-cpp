int height(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int l=height(root->left);
    int r=height(root->right);
    return max(l,r)+1;
}
bool isBalanced(TreeNode* root) {
    if(root==NULL){
        return true;
    }
    int l=height(root->left);
    int r=height(root->right);
    if (isBalanced(root->left) && isBalanced(root->right) && abs(l-r)<=1){
        return true;
    }
    else{
        return false;
    }
}
