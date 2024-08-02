void solve(int n,int i,vector<string>& ans,string& op,int last){
        if (i==n){
            ans.push_back(op);
            return;
        }
        if (last==1){
            op.push_back('0');
            solve(n,i+1,ans,op,0);
            op.pop_back();
        }
        else{
            op.push_back('0');
            solve(n,i+1,ans,op,0);
            op.pop_back();
            op.push_back('1');
            solve(n,i+1,ans,op,1);
            op.pop_back();
        }
    }
    vector<string> generateBinaryStrings(int num){
        vector<string> ans;
        if (num==1){
            ans.push_back("0");
            ans.push_back("1");
            return ans;
        }
        int i=1;
        string op="";
        op.push_back('0');
        solve(num,i,ans,op,0);
        op.pop_back();
        op.push_back('1');
        solve(num,i,ans,op,1);
        return ans;
    }
