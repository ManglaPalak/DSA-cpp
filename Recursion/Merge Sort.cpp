void merge(vector<int>& arr,int s,int e){
    int mid=s+(e-s)/2;
    int *first=new int[mid-s+1];
    int *second=new int[e-mid];
    int mainIndex=s;
    for(int i=0;i<mid-s+1;i++){
        first[i]=arr[mainIndex++];
    }
    mainIndex=mid+1;
    for(int i=0;i<e-mid;i++){
        second[i]=arr[mainIndex++];
    }
    int n1=mid-s+1;
    int n2=e-mid;
    int i=0;
    int j=0;
    mainIndex=s;
    while(i<n1 && j<n2){
        if (first[i]<second[j]){
            arr[mainIndex++]=first[i++];
        }
        else{
            arr[mainIndex++]=second[j++];
        }
    }
    while(i<n1){
        arr[mainIndex++]=first[i++];
    }
    while(j<n2){
        arr[mainIndex++]=second[j++];
    }
}
void mSort(vector<int>& arr,int s,int e){
    if (s>=e){
        return;
    }
    int mid=s+(e-s)/2;
    mSort(arr,s,mid);
    mSort(arr,mid+1,e);
    merge(arr,s,e);
}
void mergeSort(vector < int > & arr, int n) {
    mSort(arr,0,n-1);
}
