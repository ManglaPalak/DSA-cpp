bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p==NULL && q==NULL){
        return true;
    }
    if (p==NULL && q!=NULL){
        return false;
    }
    if (p!=NULL && q==NULL){
        return false;
    }
    bool lef=isSameTree(p->left,q->left);
    bool rig=isSameTree(p->right,q->right);
    bool data=p->val == q->val;
    if (lef && rig && data){
        return true;
    }
    else{
        return false;
    }
}
