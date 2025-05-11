#include <bits/stdc++.h>
using namespace std;

class Stackk{
    int topp;
    int arr[30];

public:
    Stackk(){
        topp = -1;
    }

    void push(int n){
        if(topp >= 29){
            cout << "Overflow\n";
            return;
        }
        topp++;
        arr[topp] = n;
    }

    void pop(){
        if(topp < 0){
            cout << "Underflow\n";
            return;
        }
        topp--;
    }

    int top(){
        if(topp < 0){
            cout << "Underflow\n";
            return -1;
        }
        return arr[topp];
    }

    int size(){
        return topp + 1;
    }

    bool isEmpty(){
        return topp == -1;
    }
};

int evaluatePrefix(string s){
    Stackk st;
    for(int i=s.size()-1; i>=0; i--){
        if(isdigit(s[i])){
            st.push(s[i] - '0');
        }
        else{
            int t1 = st.top();
            st.pop();
            int t2 = st.top();
            st.pop();

            switch(s[i]){
                case '+': st.push(t1 + t2); break;
                case '-': st.push(t1 - t2); break;
                case '*': st.push(t1 * t2); break;
                case '/': st.push(t1 / t2); break;
            }
        }
    }
    return st.top();
}

int main(){
    string s;
    cout << "Enter input : ";
    cin >> s;
    int ans = evaluatePrefix(s);
    cout << "Answer : " << ans << endl;
    return 0;
}