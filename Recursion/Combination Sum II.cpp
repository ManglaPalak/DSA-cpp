void solve(vector<int>& arr,int target,int index,vector<vector<int>>& result,vector<int>& ans){
        if (target==0){
            result.push_back(ans);
            return;
        }
        if (target<0){
            return;
        }
        if (index==arr.size()){
            return;
        }
        //exclude
        //solve(arr,target,index+1,result,ans);
        //include
        ans.push_back(arr[index]);
        solve(arr,target-arr[index],index+1,result,ans);
        ans.pop_back();
        int i=1;
        while(index+i<arr.size() && arr[index+i]==arr[index]){
            i++; //to remove duplicates
        }
        solve(arr,target,index+i,result,ans);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ans;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0,result,ans);
        sort(result.begin(),result.end());
        return result;
    }
