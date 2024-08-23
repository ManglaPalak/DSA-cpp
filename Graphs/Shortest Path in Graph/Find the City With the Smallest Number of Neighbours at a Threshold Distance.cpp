int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long>> dist(n,vector<long>(n,INT_MAX));
        for(auto it:edges){
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(int val=0;val<n;val++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j]=min(dist[i][j],dist[i][val]+dist[val][j]);
                }
            }
        }
        int cityNo=-1;
        int cntCity=n;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if (dist[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if (cnt<=cntCity){
                cntCity=cnt;
                cityNo=i;
            }
        }
        return cityNo;
    }
