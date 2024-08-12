vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> ans;
    if (root==NULL){
        return ans;
    }
    vector<int> pre;
    vector<int> ino;
    vector<int> post;
    stack<pair<TreeNode*,int>> st;
    st.push({root,1});
    while(!st.empty()){
        pair<TreeNode*,int> tmp=st.top();
        st.pop();
        if (tmp.second==1){
            tmp.second++;
            st.push(tmp);
            pre.push_back(tmp.first->data);

            if (tmp.first->left){
                st.push({tmp.first->left,1});
            }
        }
        else if (tmp.second==2){
            tmp.second++;
            st.push(tmp);
            ino.push_back(tmp.first->data);

            if (tmp.first->right){
                st.push({tmp.first->right,1});
            }
        }
        else{
            post.push_back(tmp.first->data);
        }
    }
    ans.push_back(ino);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}
