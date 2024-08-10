string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && k>0 && st.top()-'0' > num[i]-'0'){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        if (st.empty()){
            return "0";
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        while(res.size()>0 && res.back()=='0'){
            res.pop_back();
        }
        if (res.size()==0){
            return "0";
        }
        reverse(res.begin(),res.end());
        return res;
    }
