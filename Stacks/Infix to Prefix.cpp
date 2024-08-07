#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<string>
using namespace std;
int precedence(char c){
    if (c=='^'){
        return 3;
    }
    else if (c=='/' || c=='*'){
        return 2;
    }
    else if (c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
string infixToPostfix(string& s){
    string ans="";
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if ((c>='0' && c<='9')||(c>='a' && c<='z')||(c>='A' && c<='Z')){
            ans+=c;
        }
        else if (c=='('){
            st.push('(');
        }
        else if (c==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if (c=='^'){
                while(!st.empty() && precedence(c)<=precedence(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && precedence(c)<precedence(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
string infixToPrefix(string& s){
    string result="";
    reverse(s.begin(),s.end());
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            s[i]=')';
        }
        else if (s[i]==')'){
            s[i]='(';
        }
    }
    result=infixToPostfix(s);
    reverse(result.begin(),result.end());
    return result;
}
int main(){
    string s="a+b*(c^d-e)";
    string ans=infixToPrefix(s);
    cout<< ans << endl;
    return 0;
}
