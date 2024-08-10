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
    vector<int> findNGE(vector<int>& arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?arr.size():st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findPGE(vector<int>& arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        vector<int> nse=findNSE(nums);
        vector<int> pse=findPSE(nums);
        vector<int> nge=findNGE(nums);
        vector<int> pge=findPGE(nums);
        long long largest=0;
        long long smallest=0;
        for(int i=0;i<nums.size();i++){
            int leftS=i-pse[i];
            int rightS=nse[i]-i;
            int leftL=i-pge[i];
            int rightL=nge[i]-i;
            largest+=(rightL*leftL*1LL*nums[i]);
            smallest+=(rightS*leftS*1LL*nums[i]);
        }
        return largest-smallest;
    }
