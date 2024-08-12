pair<int,int> dmtr(TreeNode* root){
    if (root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }
  
    pair<int,int> l=dmtr(root->left); 
    pair<int,int> r=dmtr(root->right);
  
    int op1=l.first;
    int op2=r.first;
    int op3=l.second+r.second;
    pair<int,int> ans; // <diameter,height>
    ans.first=max(op1,max(op2,op3));
    ans.second=max(l.second,r.second)+1;
    return ans;
}

int diameterOfBinaryTree(TreeNode* root) {
    return dmtr(root).first;
}
