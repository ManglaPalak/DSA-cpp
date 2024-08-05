void insertAtBottom(stack<int>& St,int x){
    if (St.empty()){
        St.push(x);
        return;
    }
    int front=St.top();
    St.pop();
    insertAtBottom(St,x);
    St.push(front);
}
void Reverse(stack<int> &St){
    if (St.empty()){
        return;
    }
    int front=St.top();
    St.pop();
    Reverse(St);
    insertAtBottom(St,front);
}
