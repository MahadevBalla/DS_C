#include <bits/stdc++.h>
using namespace std;

class Stackk{
    int topp;
    int n=30;
    string arr[30];

    public:
    Stackk(){
        topp=-1;
    }

    void push(string n){
        if(topp>=29){
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

    string top(){
        if(topp<0){
            cout<<"underflow"<<endl;
            return "";
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

string prefixToInfix(string s){
    Stackk st;
    for(int i=s.size()-1; i>=0; i--){
        if(isalnum(s[i])){
            st.push(string(1,s[i]));
        }
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push('(' + t1 + s[i] + t2 + ')');
        }
    }
    return st.top();
}

int main(){
    string s;
    cout<<"Enter input : ";
    cin>>s;
    string ans = prefixToInfix(s);
    cout<<"Infix form : " + ans <<endl;
    return 0;
}