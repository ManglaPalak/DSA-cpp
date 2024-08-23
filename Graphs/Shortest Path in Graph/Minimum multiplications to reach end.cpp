int minimumMultiplications(vector<int>& arr, int start, int end) {
    if (start==end){
        return 0;
    }
    queue<pair<int,int>> q;
    q.push({start,0});
    vector<int> dist(100000,1e9);
    dist[start]=0;
    int mod=100000;
    while(!q.empty()){
        int node=q.front().first;
        int steps=q.front().second;
        q.pop();
        for(int it:arr){
            int num=(node*it)%mod;
            if (dist[num]>steps+1){
                dist[num]=steps+1;
                q.push({num,steps+1});
            }
            if (num==end){
                return steps+1;
            }
        }
    }
    return -1;
}
