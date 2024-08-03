void solve(int index,vector<int>& candidates, int target, vector<vector<int>>& ans,vector<int>& sub){
        if (target==0){
            ans.push_back(sub);
            return;
        }
        if (target < 0){
            return;
        }
        if (index==candidates.size()){
            return;
        }
        //exclude the current element case
        solve(index+1,candidates,target,ans,sub);

        //include the current element case
        sub.push_back(candidates[index]);
        solve(index,candidates,target-candidates[index],ans,sub);
        sub.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sub;
        solve(0,candidates,target,ans,sub);
        return ans;
    }
