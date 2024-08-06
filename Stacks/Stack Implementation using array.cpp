#include<iostream>
using namespace std;
class stack{
    public:
    int *arr;
    int size;
    int top;

    stack(int s){
        size=s;
        arr=new int[size];
        top=-1;
    }

    void push(int e){
        if (size-top>1){
            top++;
            arr[top]=e;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }
    
    void pop(){
        if (top==-1){
            cout<<"stack underflow"<<endl;
        }
        top--;
    }

    int peek(){
        if (top==-1){
            return -1;
        }
        return arr[top];
    }

    bool empty(){
        if (top==-1){
            return true;
        }
        else{
            return false;
        }

    }
};

int main(){
    stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    cout<< st.peek() <<endl;
    cout<< st.empty() <<endl;

    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();

    cout<< st.empty() <<endl;
    


    /*
    stack<int> s;
    s.push(8);
    s.push(7);
    s.push(9);
    s.push(10);

    s.pop();
    s.pop();

    cout<< s.top() <<endl;
    cout<< s.size() <<endl;
    cout<<s.empty() <<endl;

    s.pop();
    s.pop();

    cout<<s.empty()<<endl;
    */

}
