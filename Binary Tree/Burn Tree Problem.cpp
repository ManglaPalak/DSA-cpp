/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node* make_parent(Node* root, unordered_map<Node*,Node*>& parent, int target){
        queue<Node*> q;
        Node* trgt;
        q.push(root);
        while(!q.empty()){
            Node* tmp=q.front();
            q.pop();
            if (tmp->data==target){
                trgt=tmp;
            }
            if (tmp->left){
                parent[tmp->left]=tmp;
                q.push(tmp->left);
            }
            if (tmp->right){
                parent[tmp->right]=tmp;
                q.push(tmp->right);
            }
        }
        return trgt;
    }
    int minTime(Node* root, int target) {
        unordered_map<Node*,Node*> parent;
        Node* start=make_parent(root,parent,target);
        unordered_map<Node*,bool> visited;
        queue<Node*> q;
        q.push(start);
        int ans=0;
        visited[start]=true;
        while(!q.empty()){
            int s=q.size();
            bool isnew=false;
            for(int i=0;i<s;i++){
                Node* top=q.front();
                q.pop();
                if (top->left && !visited[top->left]){
                    visited[top->left]=true;
                    q.push(top->left);
                    isnew=true;
                }
                if (top->right && !visited[top->right]){
                    visited[top->right]=true;
                    q.push(top->right);
                    isnew=true;
                }
                if (parent[top] && !visited[parent[top]]){
                    visited[parent[top]]=true;
                    q.push(parent[top]);
                    isnew=true;
                }
            }
            if (isnew){
                ans++;
            }
        }
        return ans;
    }
};
