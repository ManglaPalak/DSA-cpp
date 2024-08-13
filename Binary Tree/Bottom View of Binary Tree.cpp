vector <int> bottomView(Node *root) {
    map<int,int> mp; //<hd,node value>
    queue<pair<Node*,int>> q; //<node,hd>
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> top=q.front();
        q.pop();
        Node* tmp=top.first;
        int hd=top.second;
        mp[hd]=tmp->data;
        if (tmp->left){
            q.push(make_pair(tmp->left,hd-1));
        }
        if (tmp->right){
            q.push(make_pair(tmp->right,hd+1));
        }
    }
    for(auto i:mp){
        ans.push_back(i.second);
    }
    return ans;
}
