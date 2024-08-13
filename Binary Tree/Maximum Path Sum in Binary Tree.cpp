int pathsum(TreeNode* root,int& maxi){
    if (root==NULL){
        return 0;
    }
    int lef=max(0,pathsum(root->left,maxi));
    int rig=max(0,pathsum(root->right,maxi));
    maxi=max(maxi,lef+rig+root->val);
    return max(lef,rig)+root->val;
}
int maxPathSum(TreeNode* root) {
    int maxi=INT_MIN;
    pathsum(root,maxi);
    return maxi;
}
