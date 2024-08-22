int minimumEffortPath(vector<vector<int>>& heights) {
    priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> diff(n, vector<int>(m, INT_MAX));
    diff[0][0]= 0;
    pq.push({0,{0,0}});
    int dr[]={-1, 0, 1, 0};
    int dc[]={0, 1, 0, -1};

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int effort= it.first;
        int row= it.second.first;
        int col= it.second.second;
        
        if(row == n-1 && col == m-1){
            return effort;
        }

        for(int i=0; i<4; i++){
            int nrow= row+dr[i];
            int ncol= col+dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                int neweff= max(abs(heights[row][col]-heights[nrow][ncol]), effort);
                if(neweff < diff[nrow][ncol]){
                    diff[nrow][ncol]= neweff;
                    pq.push({neweff, {nrow, ncol}});
                }
            }
        }
    }
    return 0;
}
