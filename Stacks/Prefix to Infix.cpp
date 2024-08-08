string preToInfix(string pre_exp) {
        stack<string> st;
        for(int j=pre_exp.size()-1;j>=0;j--){
            char x=pre_exp[j];
            if ((x>='a' && x<='z')||(x>='A' && x<='Z')){
                string op(1,pre_exp[j]);
                st.push(op);
            }
            else{
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                st.push("("+s1+pre_exp[j]+s2+")");
            }
        }
        return st.top();
    }
