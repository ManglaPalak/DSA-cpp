// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    if (root == NULL) 
        return -1;
    int ans=-1;
    if (root->data==input){
        return root->data;
    }
    Node* curr=root;
    while(curr!=NULL){
        if (curr->data > input){
            ans=curr->data;
            curr=curr->left;
        }
        else if (curr->data == input){
            return curr->data;
        }
        else{
            curr=curr->right;
        }
    }
    if (ans==-1){
        return -1;
    }
    else{
        return ans;
    }
}
