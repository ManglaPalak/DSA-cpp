int floor(Node* root, int x) {
    if (root == NULL) 
        return -1;
    int ans=-1;
    if (root->data==x){
        return root->data;
    }
    Node* curr=root;
    while(curr!=NULL){
        if (curr->data < x){
            ans=curr->data;
            curr=curr->right;
        }
        else if (curr->data == x){
            return curr->data;
        }
        else{
            curr=curr->left;
        }
    }
    if (ans==-1){
        return -1;
    }
    else{
        return ans;
    }
}
