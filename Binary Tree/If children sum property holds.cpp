int isSumProperty(Node *root){
    int left=0;
    int right=0;
    if (root==NULL || (root->left==NULL && root->right==NULL)){
        return 1;
    }
    else{
        if (root->left){
            left=root->left->data;
        }
        if (root->right){
            right=root->right->data;
        }
        if (root->data == left+right && isSumProperty(root->left)
        && isSumProperty(root->right)){
            return 1;
        }
        else{
            return 0;
        }
    }
}
