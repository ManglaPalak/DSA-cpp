long long solve(vector<int>& bt) {
    long long sum=0;
    long long wait=0;
    int n=bt.size();
    sort(bt.begin(),bt.end());
    for(int i=0;i<n-1;i++){
        wait+=bt[i];
        sum+=wait;
    }
    return sum/n;
}
