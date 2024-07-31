int lowerBound(vector<int> arr,int n,int x){
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if (arr[mid]>=x){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int rowWithMax1s(vector<vector<int> > &arr) {
        int rows=arr.size();
        int cols=arr[0].size();
        int cnt_max=0;
        int index=-1;
        for(int i=0;i<rows;i++){
            int ones_cnt=cols-lowerBound(arr[i],cols,1);
            if (ones_cnt > cnt_max){
                cnt_max=ones_cnt;
                index=i;
            }
        }
        return index;
    }
