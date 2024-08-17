/* tree node structure
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class nodeVal{
    public:
    int maxSize;
    int maxi;
    int mini;
    nodeVal(int min,int max,int size){
        this->maxSize=size;
        this->mini=min;
        this->maxi=max;
    }
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    nodeVal largestBSTinBT(Node* root){
        if (root==NULL){
            return nodeVal(INT_MAX,INT_MIN,0);
        }
        auto left=largestBSTinBT(root->left);
        auto right=largestBSTinBT(root->right);
        
        if (left.maxi < root->data && root->data < right.mini){
            return nodeVal(min(left.mini,root->data),max(root->data,right.maxi),
            left.maxSize + right.maxSize + 1);
        }
        return nodeVal(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
    }
    int largestBst(Node *root){
    	return largestBSTinBT(root).maxSize;
    }
};
