string reverseWords(string s) {
        stack<string> st;
        string sub="";
        for(int i=0;i<s.length();i++){
            if (s[i]==' '){
                if (!sub.empty()){
                    st.push(sub);
                    sub="";
                }
            }
            else{
                sub+=s[i];
            }
        }
        if (!sub.empty()){
            st.push(sub);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if (!st.empty()){
                ans+=' ';
            }
        }
        return ans;
    }
