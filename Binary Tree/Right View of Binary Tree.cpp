vector<int> rightSideView(TreeNode* root) {
        map<int,int> mp; //<lvl,node value>
        queue<pair<TreeNode*,int>> q;
        vector<int> ans;
        if (root==NULL){
            return ans;
        }
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<TreeNode*,int> top=q.front();
            q.pop();
            TreeNode* tmp=top.first;
            int lvl=top.second;
            mp[lvl]=tmp->val;
            if (tmp->left){
                q.push(make_pair(tmp->left,lvl+1));
            }
            if (tmp->right){
                q.push(make_pair(tmp->right,lvl+1));
            }
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
