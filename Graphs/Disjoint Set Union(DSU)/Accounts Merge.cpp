class DisjointSet{
    public: 
    vector<int> parent,size;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findPar(int node){
        if (node==parent[node]){
            return node;
        }
        return parent[node]=findPar(parent[node]);
    }
    void unionBySize(int u,int v){
        int pu=findPar(u);
        int pv=findPar(v);
        if (pu==pv){
            return;
        }
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mailToNode;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if (mailToNode.find(accounts[i][j])==mailToNode.end()){
                    mailToNode[accounts[i][j]]=i;
                }
                else{
                    ds.unionBySize(i,mailToNode[accounts[i][j]]);
                }
            }
        }
        vector<string> vec[n];
        for(auto mail:mailToNode){
            string str=mail.first;
            int node=ds.findPar(mail.second);
            vec[node].push_back(str);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if (vec[i].size()==0){
                continue;
            }
            sort(vec[i].begin(),vec[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(int j=0;j<vec[i].size();j++){
                temp.push_back(vec[i][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
