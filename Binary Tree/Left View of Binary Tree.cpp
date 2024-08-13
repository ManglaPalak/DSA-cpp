//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root){
    map<int,int> mp; //<lvl,node value>
    queue<pair<Node*,int>> q; //<node,lvl>
    vector<int> ans;
    if (root==NULL){
        return ans;
    }
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> top=q.front();
        q.pop();
        Node* tmp=top.first;
        int lvl=top.second;
        if (mp.find(lvl)==mp.end()){
            mp[lvl]=tmp->data;
        }
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
