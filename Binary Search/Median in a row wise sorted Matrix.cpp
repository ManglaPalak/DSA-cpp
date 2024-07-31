int upperBound(vector<int> arr,int n,int x){
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            if (arr[mid]>x){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int countSmall(vector<vector<int>> &matrix, int R, int C,int x){
        int cnt=0;
        for(int i=0;i<R;i++){
            cnt+=upperBound(matrix[i],C,x);
        }
        return cnt;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        int low=3000;
        int high=0;
        for(int i=0;i<R;i++){
            low=min(low,matrix[i][0]);
            high=max(high,matrix[i][C-1]);
        }
        int req=(R*C)/2;
        while(low<=high){
            int mid=(low+high)/2;
            int smaller=countSmall(matrix,R,C,mid);
            if (smaller<=req){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
