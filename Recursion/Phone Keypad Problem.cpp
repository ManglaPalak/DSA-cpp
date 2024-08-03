void solve(string digits,int index,vector<string>& mapping,vector<string>& result, string& op){
        if (index==digits.length()){
            result.push_back(op);
            return;
        }
        int value=digits[index]-'0';
        string chars=mapping[value];
        for(int i=0;i<chars.length();i++){
            op.push_back(chars[i]);
            solve(digits,index+1,mapping,result,op);
            op.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.length()==0){
            return result;
        }
        string op="";
        int index=0;
        vector<string> mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,index,mapping,result,op);
        return result;
    }
