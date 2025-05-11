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
};

int main(){
    string s;
    cout<<"Enter i/p: ";
    cin>>s;
    Stackk stk;
    for(auto c: s){
        if(c=='('){
            stk.push('(');
        }
        else if(c==')'){
            if(stk.top()!='('){
                cout<<"unbalanced"<<endl;
                return -1;
            }
            else stk.pop();
        }
    }
    if(stk.size()!=0){
        cout<<"unbalanced"<<endl;
        return -1;
    }
    cout<<"balanced"<<endl;
    return 0;
}