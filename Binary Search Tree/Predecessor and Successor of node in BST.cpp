// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    void Pred(Node* root, Node*& pre,int key){
        if (root==NULL){
            return;
        }
        if (root->key < key){
            pre=root;
            Pred(root->right,pre,key);
        }
        else{
            Pred(root->left,pre,key);
        }
    }
    void Succ(Node* root, Node*& suc,int key){
        if (root==NULL){
            return;
        }
        if (root->key > key){
            suc=root;
            Succ(root->left,suc,key);
        }
        else{
            Succ(root->right,suc,key);
        }
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        Pred(root,pre,key);
        Succ(root,suc,key);
    }
};
