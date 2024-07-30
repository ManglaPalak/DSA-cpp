bool isPossible(vector<int> &boards, int k,int mid){
    int painter=1;
    int cnt=0;
    for(int i=0;i<boards.size();i++){
        if (cnt+boards[i] <= mid){
            cnt+=boards[i];
        }
        else{
            painter++;
            if (painter>k || boards[i]>mid){
                return false;
            }
            cnt=boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int start=0;
    int sum=0;
    for(int i=0;i<boards.size();i++){
        sum+=boards[i];
    }
    int end=sum;
    int ans=-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if (isPossible(boards,k,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
}
