void tOH(int start,int end,int src,int aux,int des,vector<vector<int>>& ans){
    if (start>end){
        return;
    }
    tOH(start,end-1,src,des,aux,ans);
    vector<int> res;
    res.push_back(src);
    res.push_back(des);
    ans.push_back(res);
    tOH(start,end-1,aux,src,des,ans);
}
vector<vector<int>> towerOfHanoi(int n)
{
    vector<vector<int>> ans;
    tOH(1,n,1,2,3,ans);
    return ans;
}
