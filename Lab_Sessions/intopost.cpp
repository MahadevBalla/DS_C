#include <bits/stdc++.h>
using namespace std;

class Stackk{
    int topp;
    int n=20;
    char arr[20];

    public:
    Stackk(){
        topp=-1;
    }

    void push(char n){
        if(topp>=19){
            cout<<"Overflow\n";
            return;
        }     
        topp++;
        arr[topp]=n;
    }

    void pop(){
        if(topp<0){
            cout<<"Underflow\n";
            return;
        }
        topp--;
        return;
    }

    char top(){
        if(topp<0){
            cout<<"underflow"<<endl;
            return -1;
        }
        return arr[topp];
    }

    int size(){
        return topp+1;
    }

    bool isEmpty(){
        if(topp==-1){
            return true;
        }
        return false;
    }
};

// bool isOperator(char c){
//     return (c == '+' || c == '-' || c == '*' || c == '/');
// }

int precedence(char c){
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return 0;
}

string infixToPostfix(string s){
    Stackk st;
    string ans = "";
    for(auto c: s){
        if(isalnum(c)){
            ans += c;
        }
        else if(c == '('){
            st.push('(');
        }
        else if(c == ')'){
            while(!st.isEmpty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        // else if(isOperator(c)){
        else{
            while (!st.isEmpty() && precedence(c)<=precedence(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(c);           
        }
    }
    while(!st.isEmpty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}

int main(){
    string s;
    cout<<"Enter input : ";
    cin>>s;
    string ans = infixToPostfix(s);
    cout<<"Postfix form : " + ans <<endl;
    return 0;
}