vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int,map<int,multiset<int>>> mp; //<hd,<lvl,nodes list>>
    queue<pair<TreeNode*,pair<int,int>>> q; //<Node,<hd,lvl>
    vector<vector<int>> ans;
    if (root==NULL){
        return ans;
    }
    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty()){
        pair<TreeNode*,pair<int,int>> tmp=q.front();
        q.pop();
        TreeNode* node=tmp.first;
        int hd=tmp.second.first;
        int lvl=tmp.second.second;
        mp[hd][lvl].insert(node->val);
        if (node->left){
            q.push(make_pair(node->left,make_pair(hd-1,lvl+1)));
        }
        if (node->right){
            q.push(make_pair(node->right,make_pair(hd+1,lvl+1)));
        }
    }
    for(auto i:mp){
        vector<int> sub;
        for(auto j:i.second){
            sub.insert(sub.end(),j.second.begin(),j.second.end());
        }
        ans.push_back(sub);
    }
    return ans;
}
