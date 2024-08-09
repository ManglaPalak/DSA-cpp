vector<int> findNSE(vector<int>& arr){
    vector<int> ans(arr.size());
    stack<int> st;
    for(int i=arr.size()-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        ans[i]=st.empty()?arr.size():st.top();
        st.push(i);
    }
    return ans;
}
vector<int> findPSE(vector<int>& arr){
    vector<int> ans(arr.size());
    stack<int> st;
    for(int i=0;i<arr.size();i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            st.pop();
        }
        ans[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return ans;
}
int sumSubarrayMins(vector<int>& arr) {
    vector<int> nse=findNSE(arr);
    vector<int> pse=findPSE(arr);
    int ans=0;
    for(int i=0;i<arr.size();i++){
        int left=i-pse[i];
        int right=nse[i]-i;
        ans=(ans+(right*left*1LL*arr[i])%1000000007)%1000000007;
    }
    return ans;
}
