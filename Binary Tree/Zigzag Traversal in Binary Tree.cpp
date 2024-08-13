vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root==NULL){
        return ans;
    }
    queue<TreeNode*> q;
    q.push(root);
    bool l2r=true;
    while(!q.empty()){
        vector<int> sub;
        int s=q.size();
        for(int i=0;i<s;i++){
            TreeNode* front=q.front();
            q.pop();
            sub.push_back(front->val);
            if (front->left){
                q.push(front->left);
            }
            if (front->right){
                q.push(front->right);
            }
        }
        if (!l2r){
            reverse(sub.begin(),sub.end());
            ans.push_back(sub);
            l2r=!l2r;
        }
        else{
            ans.push_back(sub);
            l2r=!l2r;
        }
    }
    return ans;
}
