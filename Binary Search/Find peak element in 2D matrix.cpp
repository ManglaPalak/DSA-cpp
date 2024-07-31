int maxelement(vector<vector<int>>& mat,int rows,int cols,int mid){
        int ans=0;
        int maxi=0;
        for(int i=0;i<rows;i++){
            if (mat[i][mid]>maxi){
                maxi=mat[i][mid];
                ans=i;
            }
        }
        return ans;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows=mat.size();
        int cols=mat[0].size();
        int lowcol=0;
        int highcol=cols-1;
        while(lowcol<=highcol){
            int mid=lowcol+(highcol-lowcol)/2;
            int rowIndex=maxelement(mat,rows,cols,mid);
            int left=mid-1>=0 ? mat[rowIndex][mid-1] : -1;
            int right=mid+1<cols ? mat[rowIndex][mid+1] : -1;
            if (mat[rowIndex][mid] > left && mat[rowIndex][mid]>right){
                return {rowIndex,mid};
            }
            else if (mat[rowIndex][mid] < left){
                highcol=mid-1;
            }
            else{
                lowcol=mid+1;
            }
        }
        return {-1,-1};
    }
