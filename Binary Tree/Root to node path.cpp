bool findPath(TreeNode* root,vector<int>& ans,int node){
    if (root==NULL){
        return false;
    }
    ans.push_back(root->val);
    if (root->val==node){
        return true;
    }
    if (findPath(root->left,ans,node) || (findPath(root->right,ans,node))){
        return true;
    }
    ans.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if (A==NULL){
        return ans;
    }
    findPath(A,ans,B);
    return ans;
}
