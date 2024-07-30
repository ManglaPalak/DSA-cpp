bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        for(int i=0;i<rows;i++){
            if (matrix[i][0]<=target && matrix[i][cols-1]>=target){
                int start=0;
                int end=cols-1;
                int mid=start+(end-start)/2;
                while(start<=end){
                    if (matrix[i][mid]==target){
                        return true;
                    }
                    else if (matrix[i][mid]<target){
                        start=mid+1;
                    }
                    else{
                        end=mid-1;
                    }
                    mid=start+(end-start)/2;
                }
                return false;
            }
        }
        return false;
    }
