string findOrder(string dict[], int N, int K) {
    vector<vector<int>> adj(K);
    for(int i=0;i<N-1;i++){
        string s1=dict[i];
        string s2=dict[i+1];
        int len=min(s1.size(),s2.size());
        for(int j=0;j<len;j++){
            if (s1[j] != s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }
    string ans="";
    vector<int> indegree(K,0);
    for(int i=0;i<K;i++){
        for(int j:adj[i]){
            indegree[j]++;
        }
    }
    queue<int> q;
    for(int i=0;i<K;i++){
        if (indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int top=q.front();
        q.pop();
        ans.push_back(top+'a');
        for(int i:adj[top]){
            indegree[i]--;
            if (indegree[i]==0){
                q.push(i);
            }
        }
    }
    return ans;
}
