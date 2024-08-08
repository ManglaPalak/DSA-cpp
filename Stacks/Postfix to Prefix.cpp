string postToPre(string post_exp) {
        stack<string> st;
        for(int i=0;post_exp[i]!='\0';i++){
            char c=post_exp[i];
            if ((c>='a' && c<='z')||(c>='A' && c<='Z')){
                string op(1,post_exp[i]);
                st.push(op);
            }
            else{
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                st.push(post_exp[i]+s2+s1);
            }
        }
        return st.top();
    }
