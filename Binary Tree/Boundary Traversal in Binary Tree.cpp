void leftBoundary(Node* root,vector<int>& ans){
    if (root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    ans.push_back(root->data);
    if (root->left){
        leftBoundary(root->left,ans);
    }
    else{
        leftBoundary(root->right,ans);
    }
}
void leafnodes(Node* root,vector<int>& ans){
    if (root==NULL){
        return;
    }
    if (root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
    }
    leafnodes(root->left,ans);
    leafnodes(root->right,ans);
}
void rightBoundary(Node* root,vector<int>& ans){
    if (root==NULL ||(root->left==NULL && root->right==NULL)){
        return;
    }
    if (root->right){
        rightBoundary(root->right,ans);
    }
    else{
        rightBoundary(root->left,ans);
    }
    ans.push_back(root->data);
}
vector <int> boundary(Node *root){
    vector<int> ans;
    if (root==NULL){
        return ans;
    }
    ans.push_back(root->data);
    leftBoundary(root->left,ans);
    leafnodes(root->left,ans);
    leafnodes(root->right,ans);
    rightBoundary(root->right,ans);
    return ans;
}
